const http = require('http');

const product = {
  id: 1,
  name: 'Supreme T-Shirt',
  brand: 'Supreme',
  price: 99.99,
  options: [
      { color: 'blue' },
      { size: 'XL' }
  ]
};

const app = http.createServer((req, res) => {
  res.setHeader('Content-Type', 'application/json');
  res.statusCode = 200;
  
  res.write(JSON.stringify(product));
  res.end();
});
app.listen(3000);


