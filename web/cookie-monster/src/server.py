import quart
import sys

app = quart.Quart(__name__)

@app.route("/")
async def index():
    return await quart.render_template("index.html")

@app.route("/login", methods=["POST"])
async def login():
    login_data = await quart.request.get_json()

    if login_data["username"] == "admin" and login_data["password"] == "admin":
        is_admin = quart.request.cookies.get("isAdmin")
        if is_admin == "true":
            return {
                "flag": "OWEEK{0m_n0m_n0m_c00k135_ta5t3_n1c3}"
            }
        else:
            return {
                "error": "Only administrators can access this account."
            }
    else:
        return {
            "error": "Username and password are invalid."
        }

if __name__ == "__main__":
    app.run("0.0.0.0", port=int(sys.argv[1]))
