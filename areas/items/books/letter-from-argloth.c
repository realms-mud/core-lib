//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Letter from Argloth");
    set("short", "A Letter from Argloth");
    set("title",
        "A Letter from Argloth to the Circle of Dhuras");
    set("aliases",
        ({ "argloth letter", "dhuras correspondence",
            "a letter from argloth", "letter", "letter from arlogth" }));
    set("long",
        "A preserved letter written by Argloth to the senior members of "
        "the Circle of Dhuras. The tone is measured and respectful, yet "
        "there are subtle departures from his earlier teachings. Marginal "
        "marks suggest the text was studied closely in later years.");

    addChapter("The Letter",
        "To those whose counsel I have long trusted,\n"
        "\n"
        "I have received your concerns, and I do not dismiss them.\n"
        "It would be a failure of judgment to ignore the voices\n"
        "that have, in the past, corrected my own.\n"
        "\n"
        "You speak of my increasing isolation, and of my return\n"
        "to the lower vaults of Zhardeg. On both counts, you are\n"
        "correct in observation, if not in conclusion.\n"
        "\n"
        "The matter before us is no longer one of study alone.\n"
        "Sylthasis remains beyond our reach. What we attempted\n"
        "before was insufficient, and I will not pretend otherwise.\n"
        "\n"
        "You have reminded me, more than once, of my own words\n"
        "regarding restraint and the dangers of persuasive thought.\n"
        "I am not unaware of the irony. Nor am I immune to it.\n");
    addChapter("The Letter (cont'd)",
        "Yet I would ask you to consider whether restraint, as we\n"
        "have practiced it, has become indistinguishable from inaction.\n"
        "We preserved ourselves, and in doing so, preserved nothing else.\n"
        "\n"
        "Mirost remains a ruin. The dead remain unavenged.\n"
        "The dragon endures.\n"
        "\n"
        "If there are forms of knowledge that offer a path forward,\n"
        "however unsettling, are we justified in refusing them?\n"
        "Or do we merely defer the cost to those who cannot refuse?\n"
        "\n"
        "You fear that I am changing. In this, you are correct.\n"
        "But I would submit that change is not, in itself, error.\n"
        "To remain fixed in the face of failure is not discipline,\n"
        "but stagnation.\n"
        "\n"
        "I have not abandoned our principles. I have reexamined them.\n"
        "If they are sound, they will endure that scrutiny.\n"
        "If they are not, then it is better we discover this now.\n"
    );
    addChapter("The Letter (cont'd, pt 2)",
        "You caution against studying such matters alone.\n"
        "This is wisdom, and I have not disregarded it lightly.\n"
        "But there are conclusions that cannot be reached\n"
        "in the presence of constant dissent.\n"
        "\n"
        "Clarity requires, at times, the absence of interruption.\n"
        "\n"
        "I do not ask for your agreement.\n"
        "I ask only that you withhold judgment until results\n"
        "can be observed. If I fail, you will have been correct.\n"
        "If I succeed, then we must all reconsider what we hold\n"
        "to be permissible.\n"
        "\n"
        "I remain, as ever, committed to the purpose we share.\n"
        "That purpose has not changed.\n"
        "\n"
        "Only the means are in question.\n"
        "\n"
        "— Argloth\n"
        "[A later note in another hand: 'He had already decided.']\n");
}
