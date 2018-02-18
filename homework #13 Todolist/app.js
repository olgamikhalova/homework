var express = require('express');
var routes = require('./routes');
var http = require('http');
var path = require('path');

var tasks = require('./routes/tasks'); 
var app = express();

var connection  = require('express-myconnection'); 
var mysql = require('mysql');

// all environments
app.set('port', process.env.PORT || 4300);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
//app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.json());
app.use(express.urlencoded());
app.use(express.methodOverride());

app.use(express.static(path.join(__dirname, 'public')));

// development only
if ('development' == app.get('env')) {
  app.use(express.errorHandler());
}

app.use(
    
    connection(mysql,{
        
        host: 'localhost',
        user: 'user',
        password : '12345',
        port : 3306, //port mysql
        database:'Todolist'

    },'pool') //or single

);

app.get('/', routes.index);
app.get('/tasks', tasks.list);
app.get('/tasks/add', tasks.add);
app.post('/tasks/add', tasks.save);
app.get('/tasks/delete/:id', tasks.delete_task);
app.get('/tasks/edit/:id', tasks.edit);
app.post('/tasks/edit/:id',tasks.save_edit);


app.use(app.router);

http.createServer(app).listen(app.get('port'), function(){
  console.log('Listen port ' + app.get('port'));
});
