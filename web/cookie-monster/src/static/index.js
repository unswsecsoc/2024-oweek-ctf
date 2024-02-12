const URL = window.location.href;
const loginForm = document.getElementById("login");
const showResult = document.getElementById("result");

const showFlag = (data) => {
	showResult.className = "alert alert-success";
	showResult.innerHTML = data.flag;
}

const showError = (data) => {
	showResult.className = "alert alert-danger";
	showResult.innerHTML = data.error;
}

const sendLogin = () => {
	const username = document.getElementById("username").value;
	const password = document.getElementById("password").value;
	
	fetch(URL + "login", {
		method: "POST",
		body: JSON.stringify({
			username: username,
			password: password
		}),
		headers: {
			"Content-type": "application/json"
		}
	}).then(resp => resp.json()).then(data => {
		data.error ? showError(data) : showFlag(data);
	});

}

loginForm.addEventListener("submit", (e) => {
	e.preventDefault();
	sendLogin();
});

// Set cookie when site loads.
const setCookie = () => {
	document.cookie = "isAdmin=false; SameSite=Strict; Secure";
}

setCookie();
