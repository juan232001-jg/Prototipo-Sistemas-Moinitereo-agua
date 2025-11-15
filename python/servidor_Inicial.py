from http.server import HTTPServer, SimpleHTTPRequestHandler
import os

PORT = 8000

class MyHandler(SimpleHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.path = '/web/index.html'
        return SimpleHTTPRequestHandler.do_GET(self)

print(f"Servidor en http://localhost:{PORT}")
httpd = HTTPServer(('localhost', PORT), MyHandler)
httpd.serve_forever()