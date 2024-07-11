const uuid = require("uuid")
const fs = require("fs")

let data = fs.readFileSync("models/blog.json")
let posts = JSON.parse(data)

const getAllPosts = (req, res) => {
    posts.forEach((item) => {
      console.log(`id: ${item["id"]} title: ${item["title"]}`)
    });
    res.status(200).json({"success": true, data: posts});
} 

const createPost = (req, res) => {
    let post = {
      "id": uuid.v4(),
      "title": req.body.title,
      "username": req.body.username,
      "date": req.body.date,
      "text": req.body.text
    }
    posts.push(post);
    fs.writeFileSync("models/blog.json", JSON.stringify(posts));
    res.status(200).json({"success": true, data: post});
  }

const readPost = (req, res) => {
  for (let i = 0; i < posts.length; i++) {
    if (posts[i]["id"] === req.params.id) {
      res.status(200).json({"success": true, data: posts[i]});
      return;
    }
  }
  res.status(200).json({"success": false, data: "not found"});
}

const putPost = (req, res) => {
  for (let i = 0; i < posts.length; i++) {
    if (posts[i]["id"] === req.params.id) {
      for (const [key, value] of Object.entries(req.body)) {
        if (posts[i][key] !== undefined) {
          posts[i][key] = value;
        }
      }
      fs.writeFileSync("models/blog.json", JSON.stringify(posts));
      res.status(200).json({"success": true, data: posts[i]});
      return;
    }
  }
  res.status(200).json({"success": false, data: "id not found"});
}

const deletePost = (req, res) => {
  for (let i = 0; i < posts.length; i++) {
    if (posts[i]["id"] === req.params.id) {
      posts.splice(i, 1); 
      fs.writeFileSync("models/blog.json", JSON.stringify(posts));
      res.status(200).json({"success": true, data: posts});
      return;
    }
  }
  res.status(200).json({"success": false, data: "id not found"});
}

module.exports = {
    getAllPosts,
    createPost,
    readPost,
    putPost, 
    deletePost
}