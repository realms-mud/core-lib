//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tol-Dhurath: The Caretaker's Confession");
    set("short", "a worn tome titled 'Tol-Dhurath: The Caretaker's Confession'");
    set("title",
        "Tol-Dhurath: The Caretaker's Confession by Sir Uhrdalen");
    set("aliases",
        ({ "tol-dhurath confession", "caretaker confession",
           "uhrdalen confession", "third chronicle", "book", "journal",
            "tome", "caretaker's consfession" }));
    set("long",
        "The final account of Sir Uhrdalen, written near the end of his life. "
        "He recounts the pursuit of Bryleth, the binding that ensnared them both, "
        "and the final act he must undertake. The seeker who comes after may "
        "unravel what he cannot finish himself.");

    addChapter("Twilight",
        "I feel the weight of years, the long shadow of pursuit and obsession.\n"
        "\n"
        "Bryleth, elusive as the wind, and I, tethered to her and to the quest.\n"
        "\n"
        "I am old. My hands tremble, my mind remembers every choice, every\n"
        "failing. And yet, in the quiet moments, I see the path forward, one\n"
        "last step that must be taken.\n"
        "\n"
        "I dream of a seeker who will follow. Perhaps they will understand\n"
        "what I have learned: that power taken is a curse, and freedom given\n"
        "is a responsibility.\n");

    addChapter("The Sacrifice",
        "The runes, the verses, the poem—they are more than relics. They are\n"
        "my confession, my offering, the threads of my life woven into words.\n"
        "\n"
        "I place each rune, not for myself, but for the one who comes after.\n"
        "Every line a reminder: obedience without understanding is slavery,\n"
        "obedience with understanding is wisdom.\n"
        "\n"
        "My own freedom is no longer my concern. It is the act itself, the\n"
        "completion of the cycle, that may free another.\n");

    addChapter("The Final Vigil",
        "I wait in silence, as one waits before the last breath. The shadows\n"
        "lengthen, the torches dim. I am both witness and participant, bound\n"
        "to my own choices.\n"
        "\n"
        "Bryleth remains beyond reach, yet this act may bring the change I\n"
        "could not achieve through force or cunning.\n"
        "\n"
        "I dream of a seeker who will come, and in that dream I place my hope.\n"
        "Perhaps they will finish what I must leave unfinished, and perhaps\n"
        "they will remember that sacrifice, at the end, is the only true\n"
        "path to wisdom.\n");

    addChapter("Eternity",
        "I write these words knowing they may be my last, knowing that when\n"
        "the fire fades and the frost settles, only the stones and the runes\n"
        "will remain to speak of me.\n"
        "\n"
        "Let my story be caution and guide. Let the verses stand, each rune\n"
        "placed in honor and in warning.\n"
        "\n"
        "I go now to the end of my vigil. The seeker may come, the world may\n"
        "change, and Bryleth may yet see freedom. I have done all I can. I\n"
        "am ready.\n");
}
