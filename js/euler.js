var reset = setInterval(function() {
	console.log("reset animation!");
	var imgs = document.getElementsByClassName("animated");
	for(let img of imgs) {
		// This is not working as intended?
		// img.classList.remove("animated");
		// img.classList.add("animated");
		img.style.animation = "none";
		img.offsetHeight;
		img.style.animation = null;
	}
}, 60000);