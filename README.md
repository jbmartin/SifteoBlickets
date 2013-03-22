#Sifteo Blickets
This repository provides instructions, materials, and code for using Sifteo Cubes to implement a "blicket"-type psychology experiment.
Follow that?  If not, read on to learn what Sifteo Cubes are and what a "blicket" is! See also our recent [blog post]() about this.

#Quick start instructions
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

Congratulations! You just launched your very own blicket experiment.


#What are blickets?

The word 'blicket' is a neologism (or made up word) created by psychologists. 
However, to a psychologist or philosopher interested in how people reason and learn about causality, a blicket has the following meaning:

**blicket** (n. *plural* blickets)

1. (philosophy) An object with certain properties causing it to trigger a "blicket detector" (a device that lights up and plays music), introduced in certain experiments relating to causality and perception ([wikitonary](http://en.wiktionary.org/wiki/blicket)).

In other words a 'blicket' is basically something that can _cause_ something else (specifically, the 'blicket detector') to do something.
Just like an Aspirin might cause your headache go away, a "blicket" might make a "blicket detector" go wild (blink and play sounds).
Why call it a blicket?  Meaningless nonesense words are an important tool for studying learning and reasoning because they help to reduce or remove the influence prior knowledge.
You could rename a blicket anything ("wuz", "kez", etc...) but many experiments in causal learning have been done (arbitrarily) with the phrase 'blicket.'

Psychologists have relied on the blicket detector game as a model of how people learn new causal relationships.
How does the blicket game work?  Typically in an experiment, the researcher tells the participant that there is a box that is a "blicket detector" that will play sounds and light up when a "blicket" is placed on top if it.
In other words, the blicket will _cause_ the blicket detector to activate when the two come into physical contact.
Various objects (square blocks) are placed on the blicket detector one a time, and only certain ones cause the detector to activate.
Thus, the physical collision between the blicket and the detector causes a change of state in the detector.
The goal is to see how children and adults learn which objects _cause_ the blicket detector to activate.
This simple game lets you explore include how children and adults generalize from certain objects to other, novel ones.
For example, do people generalize based on perceptual properties, causal properties, or a mixture of these properties?

#What are Sifteo Cubes?
Sifteo offers a unique gaming platform centered around interactive 1.5 inch cubes each with their own LCD touch screen, motion sensor, accelerometer, and the ability to sense nearby cubes.
Basically, they're like programmable iPod nanos that can touch and talk to one another!
These feature packed physical computing devices present an exciting opportunity for psychologists to study how people reason and learn through physical interaction between real objects.

![][sifteo_cubes]

[sifteo_cubes]: http://www.ufunk.net/wp-content/uploads/2011/08/Sifteo-Cubes.jpg

If you'd like to learn more about Sifteo and "intelligent play," watch this TED talk by former MIT Media Lab grad student, [David Merrill](http://alumni.media.mit.edu/~dmerrill/).

<iframe src="http://embed.ted.com/talks/david_merrill_demos_siftables_the_smart_blocks.html" width="560" height="315" frameborder="0" scrolling="no" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>


#What are Sifteo Blickets?

This project, Sifteo Blickets, is a mash up of these two ideas.
In particular, we developed a simple bit of code that enables Sifteo Cubes to be used in blicket-type experiments.
One of the cubes acts as the detector and the rest are objects that may or may not work as blickets.
The blicket detector cube will activate when the right type of other cube comes in contact with the detector cube.
This project can serve as an example for others interested in using Sifteo cubes in psychological research, or in running new blicket-type experiments!


![][blicket_guts]
![][blicket_detector]

[blicket_guts]: http://depts.washington.edu/idl/images/blicket_internal_bottom.jpg
[blicket_detector]: http://depts.washington.edu/idl/images/Blicket_top.jpg

Why Sifteo Blickets?
Our system offers a number of advantages over traditional blicket-style paradigms.
First, in the traditional set-up, the experimenter has to find all the parts and build a blicket detector using hot glue gun and a soldering iron (see above photos, [for instructions on building the box see these notes](http://depts.washington.edu/idl/light_detail.htm)).
This process can be challenging, error-prone, and messy, especially if there's not an electronics expert in the lab.
Second, relying on an experimenter to appropriately and accurately toggle the blicket detector when the blicket is placed on top introduces experimental design problems.
For example, a subtle temporal delay or advance between placing the block on the divide and flipping the switch to activate the blicket might influence the learning of the causal relationship (e.g., Lagnado & Sloman, 2004).
Additionally, the confederate's anticipation of which block to test next might signal to the participant that there's something special about them aside from their ability to activate the detector.
This issue is sometimes known as [experimenter expectancy](http://en.wikipedia.org/wiki/Observer-expectancy_effect) effects and are often addressed by designs where the experimenter and participant are "blind" to which condition they have been assigned.
Finally, a hardwired blicket detector is a fixed, unchangeable device.
As a result, it is difficult to create more complicated experiments involving other types of causal patterns, interventions, or variable types.

Sifteo Cubes overcome each of the aforementioned limitations.
Each Sifteo Cube has calibrated object detecting sensors, removing any possibility of the experimenter messing up the timing when on block physically hits another one.
Sifteo provides an API (Application Programming Interface) that allows the experimenter to program the logic of the experiment and upload it to the cubes beforehand so that both the participant and the confederate are blind to the condition, avoiding any unintentional signaling.
In addition, the software can be loaded onto the cubes and carried (along with a small battery powered base station) to a testing site without needing a computer nearby.
The base station can be used to store data files for later analysis (connects using standard USB).
Most importantly, Sifteo provides endless possibilities for creating (and recreating) interesting psychological experiments beyond the blickets design.
They are particularly well suited for work with young children where using a computer mouse can be a challenge.

To begin exploring the utility of the Cubes, we implemented a version of the classic causal learning experiment by Gopnik & Sobel (2000) (i.e., the blicket experiment).

#The Experiment

The 'blickets' game was first used in a study conducted by Gopnik & Sobel (2000).
G&S looked at how the causal properties of objects (e.g., making a blicket detector flash and play music) shape young children's conceptual knowledge.
Previously, most developmental research focused on how perceptual features (color, shape, etc.) influence categorization.
This was motivated by many prominent psychologist, including Piaget, who argued that young children were unable to understand, and therefore, categorize objects based on causal properties.
To test this theory, G&S pitted perceptual features against causal ones in a simple, yet elegant, category learning paradigm.

##Materials

Gopnik and Sobel constructed seven sets of four objects out of wooden blocks.
Below is our attempt to recreate those objects using Adobe Illustrator.
These materials are freely available in the [asset folder](https://github.com/jbmartin/SifteoBlickets/tree/master/assets) of this git repository.

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
In sets 1 through 4, two objects were randomly assigned to be "blickets" in the sense that they would activate the "blicket detector."
In sets 5 and 6, two perceptually conflicting blickets were chosen to be blickets.
In set 5, for example, one blicket might be the green rounded rectangle and the other blicket might be a red rounded rectangle.
Each child was placed either in a "induction" or "categorization" condition.
In the categorization condition, the experimenter placed each of the 4 objects on the blicket detector separately and then returned them to their original spots.
The experimenter then lifted up one of the blickets and asked the child which of the other blocks was also a blicket.
In the induction condition, the experimenter described two objects as being blickets and two as not being blickets. She then placed the blicket on the detector and asked the child which of the remaining blocks would also set off the detector.

JAY:  I THINK A PARAGRAPH HERE ABOUT WHAT THE STUDY FOUND, HOW IT DECONFOUNDS FEATURE/CAUSAL LEARNING WOULD MAKE SENSE.

![][screen_shot]

[screen_shot]: https://github.com/jbmartin/SifteoBlickets/blob/master/blog_assets/screen_shot.png?raw=true


#Under the hood: C++ basics
Okay, so that was pretty cool, but you probabily want to be able to design your _own_ blicket experiment.
Sifteo uses a popular programming language called C++.
C++ isn't a great language to learn if you're just starting out, mainly because it's very unforgiving of mistakes and requires quite a bit of knowledge to do things that are trivial in scripting languages (Python, Javascript, etc.).
It shines in large scale production software suits like operating systems or video games where speed and memory are critical (e.g., tiny game cubes with limited memory and large cpu demands).
Fortunately, the Sifteo API wraps up most of the scary parts of dealing with C++ directly.
However, it still rears its ugly head from time to time.
We'll do our best to help you figure out how to deal with it or where to turn go when you're stuck.

Let's start with some C++ basics.
C++ is [_strongly typed_](http://en.wikipedia.org/wiki/Strong_typing) and [_compiled_](http://en.wikipedia.org/wiki/Interpreted_language) (i.e., not interactive).
Strong typing requires that all variables have a type (integer, string, blicket, etc) explicitly assigned to them when they are created.
Typing is important because it defines the appropriate behavior of a variable (e.g., integers add, ducks quack, and blickets set off blicket detectors, right?).
If an integer tries to quack, we want an error to prevent our program from exploding.
Suppose, for example, you want a variable to store the number of cubes (5) we want to use in our experiment.
The integer (int) data type seems appropriate, so lets give our variable a type and set it to 5.

```cpp
// Number of cubes
int n_cubes;
n_cubes = 5;
```

Notice that each expression ends in a semicolon (;) and comments (pieces of code ignored by the compiler used for annotation) are prepended with two forward slashes (//).
Setting n\_cubes equal to 'quack' throws an error because 'quack' is a string, not an integer.
Int is just one of the dozens of built in data types found in C++, many more can be found [here](http://www.cplusplus.com/doc/tutorial/variables/).
At some point, you'll want to create your own types that can have their own behaviors.
We won't go into too much depth here, but this can be done using _typedef_.
Say you want a type that defines blicket states that can either be true (on) or false (off).

```cpp
// Type for blicket state
typedef bool is_blicket_on;

// Turn blicket on
is_blicket_on blicket_state = true;
```

Note, the last line of code combines type declaration and variable assignment.
More on custom data types [here](http://www.cplusplus.com/doc/tutorial/other_data_types/).

Another key aspect of C++ is that it's "compiled."
Compiling turns human readable code into 1s and 0s that the computer can understand.
All languages are eventually compiled, but some (i.e., scripting languages) compile your code as you input, allowing you to interact with its output.
C++ requires that your code be correct (no bugs) and complete before you can use it.
The trade off between compiled and interpreted (interactive) programming languages is speed versus production.
Compiled languages generally have faster performance rates but slower code development times.

Luckily, the Sifteo API handles all of the compiling issues using a command called make.
To illustrate, once you have code ready to compile, you run

```bash
cd MyExperiment
make my_experiment
```

More on this later.

#Loading your materials

#The heart of your experiment: Main.cpp
First, lets look at the logic of main.cpp.



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
