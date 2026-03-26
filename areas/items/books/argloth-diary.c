//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Argloth's Reflections");
    set("short", "Argloth's Diary titled 'Reflections'");
    set("title",
        "Reflections of Argloth: The Temptation of Zhardeg");
    set("aliases",
        ({ "argloth reflections", "zhardeg obsession", "private journal",
            "diary", "journal", "reflections" }));
    set("long",
        "A fragment of Argloth's private musings. Written in trembling "
        "hands and under candlelight, it captures the conflict between "
        "duty, fear, and the intoxicating lure of power he glimpsed "
        "within Zhardeg. The fragment shows the very first stirrings "
        "of obsession.");

    addChapter("Fragment",
        "I read their words again, and I cannot say I am comforted.\n"
        "The Circle urges caution, fellowship, measured action. I nod.\n"
        "I know their fear is born of care. Yet they do not see what I\n"
        "have seen. Not the ruin, not the dragon, but the thing within.\n"
        "\n"
        "Zhardeg whispered. Not in sound, not in speech, but in thought\n"
        "that gnawed and shimmered. I felt it coiling, alive, around my\n"
        "intent. It promised understanding, a path through the ruin, a\n"
        "way to bend fate itself. I cannot unhear it.\n"
        "\n"
        "I remembered the letter, the plea for restraint, the words\n"
        "about fellowship. And yet I feel alone, as if the burden must\n"
        "be mine. Only mine. What they call obsession, I call clarity.\n"
        "\n"
        "I wonder if they will understand, if history will forgive. I\n"
        "have always carried duty first, wisdom second. And yet now\n"
        "something older than duty whispers of power beyond the reach\n"
        "of any council, beyond the folly of war, beyond the decay of\n"
        "the mountain halls.\n");
    addChapter("Fragment (cont'd)",
        "I write this, yet I do not share it. Not yet. I will test the\n"
        "limits, explore the bounds, and when the Circle sees, they\n"
        "will either marvel or mourn. Perhaps both.\n"
        "\n"
        "The candle burns low. The shadows in my tower lengthen and\n"
        "press against the walls. I do not fear them. I do not yet\n"
        "fear the voice that came from Zhardeg. But I will. Soon, I\n"
        "suspect, I will.\n"
        "\n"
        "[Marginal note in a spidery hand: 'I feel the edge of my\n"
        "own reason slipping. What I sought to protect may yet\n"
        "consume me.']\n");
}
