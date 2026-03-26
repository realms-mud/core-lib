//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Early Writings of Argloth");
    set("short", "A book titled 'Of Purpose'");
    set("title",
        "Collected Writings of Argloth: On Knowledge, Power, and Restraint");
    set("aliases",
        ({ "argloth early", "dhuras doctrine", "on restraint argloth",
            "of purpose", "book" }));
    set("long",
        "A collection of Argloth's writings from his early years in Dhuras, "
        "before his later obsessions took hold. These texts reflect a "
        "disciplined mind concerned with balance, restraint, and the "
        "responsibility inherent in knowledge.");

    addChapter("On the Purpose of Knowledge",
        "Knowledge is not gathered for its own sake.\n"
        "To collect without purpose is to burden the mind.\n"
        "To apply without reflection is to endanger others.\n"
        "\n"
        "Therefore, knowledge must serve understanding.\n"
        "Understanding must serve judgment.\n"
        "And judgment must serve the preservation of life.\n"
        "\n"
        "If any part of this chain is broken,\n"
        "what remains is not wisdom, but accumulation.\n");

    addChapter("On the Limits of Power",
        "Power is a tool, not an end.\n"
        "To mistake it for an end is the beginning of error.\n"
        "\n"
        "All tools impose themselves upon the one who uses them.\n"
        "The greater the tool, the greater the imposition.\n"
        "\n"
        "Thus, the wielder must ask not only what can be done,\n"
        "but what will be required in the doing.\n"
        "\n"
        "There are acts that achieve their aim,\n"
        "and in doing so, destroy the one who chose them.\n");

    addChapter("On Restraint",
        "Restraint is not the absence of action.\n"
        "It is the presence of choice.\n"
        "\n"
        "The unrestrained man is not free.\n"
        "He is driven by impulse, fear, or desire.\n"
        "\n"
        "To refrain when action is easy,\n"
        "and to act when restraint is tempting,\n"
        "these are the marks of discipline.\n"
        "\n"
        "Without restraint, power governs the wielder.\n");

    addChapter("On the Study of Dark Things",
        "There are forms of knowledge that must be approached with care.\n"
        "Not because they are forbidden,\n"
        "but because they are persuasive.\n"
        "\n"
        "The greatest danger is not corruption by force,\n"
        "but agreement by degrees.\n"
        "\n"
        "One does not step from light into darkness at once.\n"
        "One walks, and justifies each step.\n"
        "\n"
        "Therefore, no such study should be undertaken alone.\n");

    addChapter("On Counsel",
        "No mind, however disciplined, is sufficient unto itself.\n"
        "\n"
        "We are each limited by what we can perceive,\n"
        "and further by what we are willing to question.\n"
        "\n"
        "Thus, counsel is not a sign of weakness,\n"
        "but a safeguard against certainty.\n"
        "\n"
        "Where all voices agree, scrutiny must increase.\n"
        "Where dissent is silenced, error has already taken root.\n");

    addChapter("On Victory",
        "Victory is often mistaken for success.\n"
        "They are not the same.\n"
        "\n"
        "Success preserves what was worth defending.\n"
        "Victory may destroy it.\n"
        "\n"
        "If, in overcoming the enemy, one becomes as they are,\n"
        "then the distinction between them is lost.\n"
        "\n"
        "In such a case, the enemy has not been defeated,\n"
        "but continued by other means.\n");

    addChapter("On the Dead",
        "The dead are not to be made instruments.\n"
        "They are the conclusion of a life lived.\n"
        "\n"
        "To disturb that conclusion is to deny its meaning.\n"
        "\n"
        "We honor the dead not for their usefulness,\n"
        "but for their having been.\n"
        "\n"
        "If we forget this, we will begin to measure the living\n"
        "by the same standard.\n");

    addChapter("On Fear",
        "Fear is not an enemy to be destroyed.\n"
        "It is a signal to be understood.\n"
        "\n"
        "To act without fear is not courage,\n"
        "but ignorance.\n"
        "\n"
        "To act in spite of fear may be courage,\n"
        "or it may be folly.\n"
        "\n"
        "The difference lies in whether one has listened.\n");

    addChapter("On Endings",
        "Not all things are meant to be overcome.\n"
        "\n"
        "There are forces in the world that cannot be mastered,\n"
        "only endured, avoided, or outlasted.\n"
        "\n"
        "To insist upon mastery in all things\n"
        "is to invite destruction.\n"
        "\n"
        "Wisdom lies in knowing what must be faced,\n"
        "and what must be left beyond reach.\n");

    addChapter("Final Instruction to the Scions",
        "If you remember nothing else, remember this:\n"
        "\n"
        "You are not diminished by what you refuse to do.\n"
        "\n"
        "There will come a time when power offers you a path.\n"
        "It will appear necessary. It will appear justified.\n"
        "\n"
        "You must ask not whether it succeeds,\n"
        "but whether you remain yourself in its wake.\n"
        "\n"
        "For there are victories from which there is no return.\n");
}
