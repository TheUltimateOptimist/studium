const uuid = require("uuid")
const fs = require("fs")

let data = fs.readFileSync("models/user.json")
let users = JSON.parse(data)

const getAllUsers = (req, res) => {
    res.status(200).json({"success": true, data: users});
} 

const createUser = (req, res) => {
    let user = {
      "id": uuid.v4(),
      "username": req.body.username,
      "password": req.body.password,
      "email": req.body.email
    }
    users.push(user);
    fs.writeFileSync("models/user.json", JSON.stringify(users));
    res.status(200).json({"success": true, data: user});
  }

const getUser = (req, res) => {
  for (let i = 0; i < users.length; i++) {
    if (users[i]["id"] === req.params.id) {
      res.status(200).json({"success": true, data: users[i]});
      return;
    }
  }
  res.status(200).json({"success": false, data: "id not found"});
}

const updateUser = (req, res) => {
  for (let i = 0; i < users.length; i++) {
    if (users[i]["id"] === req.params.id) {
      for (const [key, value] of Object.entries(req.body)) {
        if (users[i][key] !== undefined) {
          users[i][key] = value;
        }
      }
      fs.writeFileSync("models/user.json", JSON.stringify(users));
      res.status(200).json({"success": true, data: users[i]});
      return;
    }
  }
  res.status(200).json({"success": true, data: "id not found"});
}

const deleteUser = (req, res) => {
  for (let i = 0; i < users.length; i++) {
    if (users[i]["id"] === req.params.id) {
      users.splice(i, 1); 
      fs.writeFileSync("models/user.json", JSON.stringify(users));
      res.status(200).json({"success": true, data: users});
      return;
    }
  }
  res.status(200).json({"success": true, data: users});
}

module.exports = {
    getAllUsers,
    createUser,
    getUser,
    updateUser, 
    deleteUser
}