#Sifteo Blickets
This repository provides instructions, materials, and code for creating Sifteo "blickets" to accompany our [blog post]().

#Quick start
Sifteo provides a _free simulator_, so you can follow this tutorial without purchasing any Sifteo cubes.

Install the SDK from Sifteo ([SDK download](https://developers.sifteo.com/docs/SifteoSDK/0.9.8/getting_started.html))

Clone this repo

```bash
git clone https://github.com/jbmartin/SifteoBlickets.git 
```

Start "siftulator" (simulator)

* Windows: double click sifteo-sdk-shell.cmd
* Mac OS X: double click sifteo-sdk-shell.command
* Linux: run sifteo-sdk-shell.sh

Inside the SDK, navigate to this tutorial, build and run it

```bash
cd SifteoBlickets
make
siftulator -n 5 SifteoBlickets.elf
```

Congratulations! You just ran your own blicket experiment.


#What are blickets?

Exactly!
There's no such thing as a blicket; it's neologism created by psychologists to avoid people from having preconceived notions about what it is/isn't or what it can/can't do.
Empty (aka blank) terms are an important tool for studying learning and reasoning because they reduce or remove prior knowledge, allowing researchers to interpret their findings as a (more or less) direct result of their manipulation(s).
Alternatively, if researchers were to ask participants to reason about things they already have strong beliefs about or experience with (e.g., adults and politics or children and toys), it's not clear how much affect a 15 minute experiment would have on getting them to change such beliefs.

**blicket** (n. *plural* blickets)

1. (philosophy) An object with certain properties causing it to trigger a "blicket detector" (a device that lights up and plays music), introduced in certain experiments relating to causality and perception ([wikitonary](http://en.wiktionary.org/wiki/blicket)).

#What are Sifteo Cubes?
Sifteo offers a unique gaming platform centered around interactive 1.5 inch cubes each with their own LCD touch screen, motion sensor, accelerometer, and nearby object sensing abilities.
Basically, they're programmable iPod nanos that can touch and talk to one another!
These feature packed little cubes present an exciting opportunity for psychologists to study how people reason and learn about physical interactions in an engaging, gamified setting.

![][sifteo_cubes]

[sifteo_cubes]: http://www.ufunk.net/wp-content/uploads/2011/08/Sifteo-Cubes.jpg

Traditionally, psychologist have relied on using blicket detectors to emulate causal relationships.
For example, an experimenter might show a child several wooden blocks with various perceptual properties (e.g., color, size, shape) and then place them individually on top of a homemade light box (aka blicket detector).
If an object is a blicket, the experimenter toggles a hidden switch that causes the box to flash and play music.
The goal is to see how the child generalizes from tested objects to novel ones: Does the child generalize based on perceptual, causal, or a mixture of properties?

![][blicket_guts]
![][blicket_detector]

[blicket_guts]: http://depts.washington.edu/idl/images/blicket_internal_bottom.jpg
[blicket_detector]: http://depts.washington.edu/idl/images/Blicket_top.jpg


This approach has several practical limitations.
First, the experimenter has to find all the parts and build a blicket detector using hot glue gun and a soldering iron ([instructions](http://depts.washington.edu/idl/light_detail.htm)).
This process can be an expensive and challenging, especially if she's not an electrician.
Second, relying on a confederate to appropriately and accurately toggle the blicket detector introduces experimental design problems.
An inconsistent temporal delay or advance might cause a participant to question validity of the causal relationship.
Additionally, the confederate's anticipation of upcoming blickets might signal to the participants that there's something special about them aside from their causal properties.
Finally, it would be difficult to create more complicated experiments involving causal interventions and/or continuous variables.

Sifteo overcomes each of the aforementioned limitations.
Each Sifteo Cube has calibrated object detecting sensors, removing any possibility of a confederate botching collision timing.
Sifteo provides an API (Application Programming Interface) that allows the experimenter to program the logic of the experiment and upload it to the cubes beforehand so that both the participant and the confederate are blind to the condition, avoiding any unintentional signaling.
Most importantly, Sifteo provides endless possibilities for creating (and recreating) interesting psychological experiments.

To illustrate, we recreate a classic causal learning experiment by Gopnik & Sobel (2000) using Sifteo Cubes.


If you'd like to learn more about Sifteo and "intelligent play," watch this TED talk by former MIT Media Lab grad student, [David Merrill](http://alumni.media.mit.edu/~dmerrill/).

<iframe src="http://embed.ted.com/talks/david_merrill_demos_siftables_the_smart_blocks.html" width="560" height="315" frameborder="0" scrolling="no" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>

#Experiment

Blickets were first used in a seminal developmental study conducted by Gopnik & Sobel (2000).
They looked at how the causal properties of objects (e.g., making a blicket detector flash and play music) shape toddlers conceptual knowledge.
Previously, most developmental research focused on how perceptual features (color, shape, etc.) influence categorization.
This was motivated by many prominent psychologist, including Piaget, theorizing that young children were unable to understand, and therefore, categorize objects based on causal properties.
To test this theory, Gopnik and Sobel pitted perceptual features against causal ones in a simple, yet elegant, category learning paradigm.


##Materials

To pit various perceptual features, such as color and shape, against causal ones, Gopnik and Sobel constructed seven sets of four objects out of wooden blocks.
Below is our attempt to recreate those objects using Adobe Illustrator. These materials are freely available in the [asset folder](https://github.com/jbmartin/SifteoBlickets/tree/master/assets) of this git repository.

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

##Procedure

An experimenter presented seven sets of the four objects (shown above) to children.
Set 1 was always presented first, followed by sets 2 through 7 at random.
In sets 1 through 4, two objects were randomly assigned to be blickets.
In sets 5 and 6, two perceptually conflicting blickets were chosen.
In set 5, for example, one blicket might be the green rounded rectangle and the other blicket might be a red rounded rectangle.
Each child was placed either in the "induction" or "categorization" condition.
In the categorization condition, the experimenter placed each of the 4 objects on the blicket detector separately and then returned them to their original spots.
The experimenter then lifted up one of the blickets and asked the child which of the other blocks was also a blicket.
In the induction condition, the experimenter described two objects as being blickets and two as not being blickets. She then placed the blicket on the detector and asked the child which of the remaining blocks would also set off the detector.


![][screen_shot]

[screen_shot]: https://github.com/jbmartin/SifteoBlickets/blob/master/blog_assets/screen_shot.png?raw=true

#Under the hood: Into the darkness known as C++
Okay, so that was pretty cool, but you probabily want to be able to design your _own_  blicket experiment.
Sifteo uses a popular programming language called C++.
I'm not going lie, C++ isn't a great language to learn if you're just starting out.
It's very unforgiving of mistakes and requires quite a bit of knowledge to things that are trivial in scripting languages (Python, Javascript, etc.).
It's mainly shines in large scale production software suits like operating systems or video games where speed and memory are critical (e.g., tiny game cubes with limited memory and large cpu demands).
Fortunately, the Sifteo API wraps up most of the scary parts of dealing with C++ directly.
However, it still rears its ugly head from time to time.
We'll do our best to help you figure out how to deal with it or where to turn go when you're stuck.

First lets look at the basic logic of main.cpp.

Todo(Jay):
Discuss
- [ ] neighborhoods
- [ ] touch events
- [ ] callbacks
- [ ] sprites
- [ ] audio


#Advanced
## Interventions (touch screen + neighborhoods)
## Continuous causal power (tilt)

##Additional resources
* [Getting Oriented with the Sifteo SDK](http://tech.sifteo.com/2013/01/08/getting-oriented-with-the-sifteo-sdk/)
* [Getting Started: Basic Animation](http://tech.sifteo.com/2013/01/22/getting-started-basic-animation/)
* [Neighborhoods and Locality](http://tech.sifteo.com/2013/01/03/neighborhoods-and-locality/)
* [C++ basics](http://www.cprogramming.com/tutorial.html)
