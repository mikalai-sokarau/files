const http = require('http');
const fs = require('fs');

const app = http.createServer((req, res) => {
  try {
    res.setHeader('Content-Type', 'text/html');
    res.statusCode = 200;

    fs.createReadStream('./index.html').pipe(res);
  } catch (e) {
    res.statusCode = 500;
    res.statusMessage = 'Server error';
  }
});
app.listen(3000);
