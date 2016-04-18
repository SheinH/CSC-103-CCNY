#A Simple Paragraph Justifier
The mission of this assignment is to realize a simple paragraph justifier. As shown in my coding demonstration, your program will keep reading lines of text image using getline(). After reading a paragraph, it adjusts all the lines into an instructed width, so that it can show the words evenly spread out and fit in a straight edge at both margins (similar to "align full" option in a Microsoft word document).
This can be relatively easily done as we are dealing with a mono-space font set (not a proportional font set) shown on a command-line-type console. As an example, consider a line containing 5 words and 30 characters altogether. If this line needs to be justified into a 40-character width, the remaining10 spaces needs to be spread out between the words. Assume that the first word of the next line has more than 9 characters, that is, the word in the next line cannot be placed in the tail of this line so as to consume the extra spaces.
In this case, 2 spaces are placed between the first 4 words, followed by 4 spaces prior to the last word (tail adjustment), or 3 spaces are placed between the first 4 words, followed by a space prior to the last word (even adjustment). 
The requirements of this assignment are:
	1.	program keeps reading lines of text until reading an empty line 
	2.	program then reads a width for the read paragraph
	3.	program then justifies the paragraph based on tail adjustment 
	4.	program then shows the result in a bounding box
	5.	program allows to adjust the paragraph by going back to 2
	6.	program ends when it reads 0 as a new width
Extra points (2 points) will be considered for even adjustment implementation.
Here is a hint to realize this mission - lines of words, say vector<string> words, is a straightforward conversion as implemented in the previous assignment and posted lecture example. Now, user types some width for justification. Let this width be W. The mission is to fill i-words in one line of this W. Note i > 0, i.e., every line must have at least one word. The logic will be:
	1.	let { w1, w2, ..., wi } be a collection of words. Then, w1.length() + w2.length() + ... + wi.length() is the total length of this collection 
	2.	since we need at least one space between these i words, we need i - 1 spaces at least, and therefore, we need Wmin = w1.length() + w2.length() + ... + wi.length() + (i - 1) characters, which must be less than or equal to W
	3.	your first loop must identify this i and Wmin by going through vector<string> words you created
	4.	in the second loop, you simply create a line by adding w1 through wi-1 by placing a space between the two consecutive words
	5.	before placing the last word wi, you need to place W - Wmin spaces because this number is the excess spaces to fill in for justification (tail adjustment)!
There is no miracle or hidden trick to deal with these operations.The left-hand side of the next example shows tail adjustment while the right-hand side shows even adjustment:
```
Enter text, empty return will quit the input
> Every photo, every edit, every album now lives 
> in your iCloud Photo Library, easily viewable 
> and consistent on all your devices. 
> Automatically. The all-new Photos app makes 
> it simpler than ever to find and rediscover   
> your favorite photos. And you can make every 
> shot look even better immediately after you've 
> taken it with powerful new editing tools.
>
> Enter the width of text: 25
|-------------------------|
|very photo, every   edit,|
|every album now lives  in|
|your     iCloud     Photo|
|Library, easily  viewable|
|and  consistent  on   all|
|your             devices.|
|Automatically.        The|
|all-new Photos app  makes|
|it simpler than ever   to|
|find and rediscover  your|
|favorite photos. And  you|
|can make every shot  look|
|even  better  immediately|
|after  you've  taken   it|
|with powerful new editing|
|tools.                   |
|-------------------------|
Enter the width of text: 30
|------------------------------|
|very photo, every edit,  every|
|album now lives in your iCloud|
|Photo Library, easily viewable|
|and  consistent  on  all  your|
|devices.  Automatically.   The|
|all-new Photos app makes    it|
|simpler than ever to find  and|
|rediscover    your    favorite|
|photos. And you can make every|
|shot    look    even    better|
|immediately after you've taken|
|it with powerful new   editing|
|tools.                        |
|------------------------------|
Enter the width of text: 0
```
```
 Enter text, empty return will quit the input
>  Every photo, every edit, every album now lives
> in your iCloud Photo Library, easily viewable 
>  and consistent on all your devices. 
> Automatically. The all-new Photos app makes 
> it simpler than ever to find and rediscover   
>  your favorite photos. And you can make every 
> shot look even better immediately after you've 
> taken it with powerful new editing tools.
>
> Enter the width of text: 25
|-------------------------|
|Every  photo, every edit,|
|every  album now lives in|
|your     iCloud     Photo|
|Library,  easily viewable|
|and   consistent  on  all|
|your             devices.|
|Automatically.        The|
|all-new  Photos app makes|
|it  simpler  than ever to|
|find  and rediscover your|
|favorite  photos. And you|
|can  make every shot look|
|even  better  immediately|
|after   you've  taken  it|
|with powerful new editing|
|tools.                   |
|-------------------------|
Enter the width of text: 30
|------------------------------|
|Every photo, every edit, every|
|album now lives in your iCloud|
|Photo Library, easily viewable|
|and  consistent  on  all  your|
|devices.   Automatically.  The|
|all-new  Photos  app  makes it|
|simpler  than ever to find and|
|rediscover    your    favorite|
|photos. And you can make every|
|shot    look    even    better|
|immediately after you've taken|
|it  with  powerful new editing|
|tools.                        |
|------------------------------|
Enter the width of text: 0
```
