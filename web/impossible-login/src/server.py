import quart
import sys

app = quart.Quart("/funni/directory/that/you/will/never/find/flag.txt")

@app.route("/")
async def present():
    return await quart.send_file("index.html")

@app.route("/login", methods=["POST"])
async def login():
    details = await quart.request.form
    username = details["username"]
    password = details["password"]
    return await quart.send_file("success.html") if username == "root" and password == "correct horse battery staple" else await quart.send_file("fail.html")

if __name__ == "__main__":
    app.run("0.0.0.0", port=int(sys.argv[1]))
