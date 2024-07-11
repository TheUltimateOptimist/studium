var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Start', name: "jonathan"});
});

router.get('/profile', function(req, res, next) {
  res.render('profile', { title: 'Profil', name: "jonathan"});
});

router.post('/upload', function(req, res, next) {
  let file = req.files.file;
  file.mv('public/uploads/' + file.name);
  console.log(file.name);
  res.send("file uploaded");
})

module.exports = router;
