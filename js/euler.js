
var readMore = false;

function toggleReadMore() {
	if(readMore == true) {
		readMore = false;
	} else {
		readMore = true;
	}

	if(readMore) {
		document.getElementById("readMoreWrapper").style.display = "flex";
		document.getElementById("readMore").style.display = "none";
		document.getElementById("readLess").style.display = "block";
		// document.getElementById("readMoreWrapper").scrollIntoView();
	} else {
		document.getElementById("readMoreWrapper").style.display = "none";
		document.getElementById("readMore").style.display = "block";
		document.getElementById("readLess").style.display = "none";
		document.getElementById("changelog").scrollIntoView();
	}
}

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