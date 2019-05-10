# Change Log #

## v0.2.2 ##
#### May 10th, 2019 ####

* Fixed bug with `ls`.
* Updated `read(ParasedCommand&)` -> `read(string &filepath)`.
* Updated website.

## v0.2.1 ##
#### May 9th, 2019 ####

* Reformatted code. Should look nice and spiffy.
- OS dependendent code now all wrapped in `#if`'s
- Euler problems now need to define only one function.
- Tweaked function output formatting.

* Removed dealing with `void*`. `DataItem.get()` now returns a `bool` and sets a var by reference to return it's value.

## v0.2.0 ##
#### May 8th, 2019 ####

* Added `pwd`, `cd`, `ls`, and `read`. Support only for Unix family of operating systems.
* Added `src/js/e001/e001.js`.
