#Sifteo Blickets

 This repository provides instructions, materials, and code for creating Sifteo "blickets." Sifteo blocks not required (see simulator section below).

##What are blickets?

Exactly!
There's no such thing as a blicket; it's neologism created by psychologist to avoid people from having preconceived notions about what it is/isn't or what it can/can't do.
Empty (aka blank) terms are an important tool for studying learning and reasoning because they reduce or remove prior knowledge, allowing researchers to interpret their findings as a (more or less) direct result of their manipulation(s).
Alternatively, if researchers were to ask participants to reason about things they already have strong beliefs about or experience with (e.g., adults and politics or children and toys), it's not clear how much affect a 15 minute experiment would have on getting them to change such beliefs.

**blicket** (n. *plural* blickets)

1. (*philosophy*) An object with certain properties causing it to trigger a "blicket detector" (a device that lights up and plays music), introduced in certain experiments relating to causality and perception ([wikitonary](http://en.wiktionary.org/wiki/blicket)).

Blickets have been used extensively for studying how people, mainly children, learn and reason about causality. 
These studies use a blicket detector (shown below) to identify blickets.
The experimenter places objects (usually wooden blocks of various shapes and colors) on top of the blicket detector.
If the object is a blicket, predetermined by the experimenter, the light panel of the blicket detector flashes and an internal mechanism plays a short tune (You can build your own! [Traditional blicket detector instructions](http://depts.washington.edu/idl/light_detail.htm)).
In reality, the "blicketness" of an object is entirely arbitrary, so their's no way to actually detect it.
The detector is set off by a hidden switch toggled by the experimenter's foot.

![][blicket_guts]
![][blicket_detector]

[blicket_guts]: http://depts.washington.edu/idl/images/blicket_internal_bottom.jpg
[blicket_detector]: http://depts.washington.edu/idl/images/Blicket_top.jpg

Blickets were first used in a seminal developmental study conducted by Gopnik & Sobel (2000).
They looked at how the causal properties of objects (e.g., making a blicket detector flash and play music) shape toddlers conceptual knowledge.
Previously, most developmental research focused on how perceptual features (color, shape, etc.) influence categorization.
This was largely due to many prominent psychologist, including Piaget, theorizing that young children were unable to understand, and therefore, categorize objects based on causal properties.
To test this theory, Gopnik and Sobel pitted perceptual features against causal ones in a simple, yet elegant, category learning paradigm.

###Materials

To pit various perceptual features, such as color and shape, against causal ones, Gopnik and Sobel constructed seven sets of four objects out of wooden blocks. Below is our attempt to recreate those objects using using Adobe Illustrator. These materials are freely available under the [asset folder](https://github.com/jbmartin/SifteoBlickets/tree/master/assets) of this git repo.

####Set 1: Four Identical Objects:
![][green_rect]  ![][green_rect]  ![][green_rect] ![][green_rect]

####Set 2: Same Color Different Shape:
![][green_rect]  ![][green_sq]  ![][green_rounded_rect] ![][green_oval]

####Set 3: Same Shape Different Color:
![][red_rect]  ![][green_rect]  ![][yellow_rect] ![][blue_rect]

####Set 4: Different Colors Different Shapes:
![][green_sq]  ![][blue_oval]  ![][red_tri] ![][yellow_rounded_rect]

####Set 5: Same Shape Conflicts Color:
![][green_rounded_rect]  ![][green_rounded_rect]  ![][red_rounded_rect] ![][red_rounded_rect]

####Set 6: Same Color Conflicts Shape:
![][green_rounded_rect]  ![][green_rounded_rect]  ![][green_sq] ![][green_sq]

####Set 7: Conflicts Shape and Color:
![][red_rect]  ![][red_rect]  ![][green_sq] ![][green_sq]

[green_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/green_rect.png?raw=true
[red_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/red_rect.png?raw=true
[yellow_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/yellow_rect.png?raw=true
[green_oval]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/green_oval.png?raw=true
[green_sq]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/green_sq.png?raw=true
[green_rounded_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/green_rounded_rect.png?raw=true
[blue_oval]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/blue_oval.png?raw=true
[blue_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/blue_rect.png?raw=true
[red_tri]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/red_tri.png?raw=true
[yellow_rounded_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/yellow_rounded_rect.png?raw=true
[red_rounded_rect]: https://github.com/jbmartin/SifteoBlickets/blob/master/assets/red_rounded_rect.png?raw=true

###Procedure
![][screen_shot]

[screen_shot]: https://github.com/jbmartin/SifteoBlickets/blob/master/blog_assets/screen_shot.png?raw=true

##How do Sifteo blocks help?
Brief description and links

##Basics
0. Preinstallation (check on dependencies e.g., clang, c++, etc.)
1. Install the SDK from Sifteo
  - [SDK](https://developers.sifteo.com/docs/SifteoSDK/0.9.8/getting_started.html)
3. Clone this repo
4. Run Siftulator (simulator)
5. ...

##Advanced
1. Interventions (touch screen + neighborhoods)
2. Continuous causal power (tilt)

##Additional resources
* [Getting Oriented with the Sifteo SDK](http://tech.sifteo.com/2013/01/08/getting-oriented-with-the-sifteo-sdk/)
* [Getting Started: Basic Animation](http://tech.sifteo.com/2013/01/22/getting-started-basic-animation/)
* [Neighborhoods and Locality](http://tech.sifteo.com/2013/01/03/neighborhoods-and-locality/)
* [C++ basics](http://www.cprogramming.com/tutorial.html)
