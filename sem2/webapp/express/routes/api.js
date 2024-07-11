var express = require('express');
var router = express.Router();
var controller = require("../controllers/blogController")
var userController = require("../controllers/userController")

router.route('/blog')
  .get((req, res, __) => {
    controller.getAllPosts(req, res);
    
  })
  .post((req, res, _) => {
    controller.createPost(req, res); 
  });

router.route('/blog/:id')
  .get(function(req, res, __){
    controller.readPost(req, res);
  })
  .put(function(req, res, __) {
    controller.putPost(req, res);
  })
  .delete(function(req, res) {
    controller.deletePost(req, res);
  });

router.route('/users')
  .get((req, res, __) => {
    userController.getAllUsers(req, res);
    
  })
  .post((req, res, _) => {
    userController.createUser(req, res); 
  });

router.route('/users/:id')
  .get(function(req, res, __){
    userController.getUser(req, res);
  })
  .put(function(req, res, __) {
    userController.updateUser(req, res);
  })
  .delete(function(req, res) {
    userController.deleteUser(req, res);
  });

module.exports = router;