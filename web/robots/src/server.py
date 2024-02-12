import quart
import sys

app = quart.Quart(__name__, static_folder='static', static_url_path='')

@app.route("/")
async def index():
    return await quart.send_file("index.html")

if __name__ == "__main__":
    app.run("0.0.0.0", port=int(sys.argv[1]))
