// 001/e001.js
function euler1(const1, const2, max) {
	// Validated input data.
	if(const1 <= 0 || const2 <= 0 || max >= 1000) {
		console.log("bad data!"); 
		return; 
	}
	
	// Perform the caluculation.
	var sum = 0;
	
	for(var i = 0; i*const1 < max; i++) { sum += i*const1; }
	for(var i = 0; i*const2 < max; i++) { sum += i*const2; }
	for(var i = 0; i*const1*const2 < max; i++) { sum -= i*const1*const2; }

	console.log("result: " + sum);
}

// Start clock.
var t0 = new Date()
euler1(3, 5, 10);
// End clock.
var t1 = new Date()

// Print time the solution took in milliseconds.
console.log("time: " + (t1 - t0) + "ms")