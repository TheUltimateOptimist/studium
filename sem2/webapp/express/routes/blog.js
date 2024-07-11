var express = require('express');
var router = express.Router();
var controller = require("../controllers/blogController")

router.route('/')
  .get((req, res, __) => {
    controller.getAllPosts(req, res);
    
  })
  .post((req, res, _) => {
    controller.createPost(req, res); 
    res.redirect("/blog");
  });

router.get('/newPost', function(req, res, __){
  res.render('blogpost');
});

router.get('/:id', function(req, res, __){
  controller.readPost(req, res);
});

module.exports = router;