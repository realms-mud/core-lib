//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "On Mirost");
    set("short", "A book titled 'On Mirost'");
    set("title",
        "Kuarl, Son of Kuarl: On Mirost");
    set("aliases",
        ({ "kuarl account", "mirost fall dwarf", "sylthasis memory", "on mirost",
            "book" }));
    set("long",
        "A firsthand account written by Kuarl, a dwarf of Khazurath, "
        "who stood in Mirost when Sylthasis came. It records not "
        "glory, but fire, failure, and the breaking of certainty.");

    addChapter("We Thought Stone Was Enough",
        "We had seen one dragon fall.\n"
        "Ilzhagash died under hammer and axe.\n"
        "We said no wyrm could stand before the League.\n"
        "I believed that. We all did.\n"
        "Mirost's walls were strong. I had walked them myself.\n"
        "Good stone. Honest work. It should have held.\n"
        "When the alarms came, I took up my axe without doubt.\n"
        "Another dragon, they said. We knew what to do.\n"
        "That was before we saw her.\n"
        "Before the sky changed color.\n");

    addChapter("The First Sight",
        "She came out of the clouds like something torn loose.\n"
        "Not descending. Falling, like the world had rejected her.\n"
        "The light bent around her. I remember that clearly.\n"
        "Not shadow. Something worse.\n"
        "Men started shouting orders. Dwarves said nothing.\n"
        "We formed where we were told, shields set, axes ready.\n"
        "Then she opened her jaws.\n"
        "The first breath did not look like fire.\n"
        "It looked like the air itself was burning.\n"
        "The wall did not break. It vanished.\n");

    addChapter("Holding the Gate",
        "We moved to the inner gate, what was left of it.\n"
        "Stone was cracked, running like melted wax in places.\n"
        "I remember touching it. It was still warm.\n"
        "We set a line. Dwarves in the front. Men behind.\n"
        "An officer kept shouting. I never saw his face.\n"
        "It did not matter.\n"
        "She came through the breach without slowing.\n"
        "Too large. Too certain. Like nothing could oppose her.\n"
        "We struck when she entered.\n"
        "The sound was wrong. Metal on something that did not care.\n");

    addChapter("What Broke Us",
        "I have fought orcs in tunnels no wider than my shoulders.\n"
        "I have seen men crushed under cave-ins and kept digging.\n"
        "This was not like that.\n"
        "Our axes bit. I know they did.\n"
        "But it was like cutting a mountain that bleeds fire.\n"
        "She moved once, and five of us were gone.\n"
        "Not thrown. Not crushed. Gone.\n"
        "The line bent. Then it folded.\n"
        "No one called retreat. We just stopped holding.\n"
        "That was the moment. Not when the walls fell.\n"
        "When we understood we could not stop her.\n");

    addChapter("Inside the Fire",
        "After that, it was fragments.\n"
        "A man trying to drag his brother by the arm.\n"
        "The arm came free. He kept pulling it anyway.\n"
        "A dwarf I knew laughing while his beard burned.\n"
        "I do not think he knew.\n"
        "The streets were full of people who had nowhere to go.\n"
        "Fire moves faster than feet.\n"
        "I tried to help a child. I do not know what happened to him.\n"
        "There was a sound like a deep bell, over and over.\n"
        "It took me time to realize it was screaming.\n"
        "Everything was screaming.\n");

    addChapter("Leaving Mirost",
        "I do not remember deciding to leave.\n"
        "One moment I was in the street. Then I was outside the walls.\n"
        "Others were there. Not many. No one spoke.\n"
        "We watched the city burn.\n"
        "The flames were too bright. They did not flicker like fire.\n"
        "She was still moving inside, a shape in the light.\n"
        "Someone said we should go back.\n"
        "No one moved.\n"
        "I think that was when I knew it was over.\n"
        "Not when the dragon came. When we stood and watched.\n");

    addChapter("After",
        "We were taught that dragons can be slain.\n"
        "That is a true thing. I have seen it done.\n"
        "But not all of them.\n"
        "Some are different. Older, or worse, or chosen by something.\n"
        "I do not know.\n"
        "I only know that Mirost is gone.\n"
        "Stone failed. Steel failed. We failed.\n"
        "I still carry my axe. I still keep it sharp.\n"
        "But I do not say what I used to say.\n"
        "I do not say that we can kill them all.\n");
}
