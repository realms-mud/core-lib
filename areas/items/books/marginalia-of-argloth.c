//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Marginalia of Argloth");
    set("short", "A diary of Argloth's thoughts");
    set("title",
        "Marginalia of Argloth upon the Zhardeg Fragment");
    set("aliases",
        ({ "argloth notes", "zhardeg marginalia", "annotated fragment",
            "diary", "a diary of Argloth's thougts", "argloth's thoughts",
            "book" }));
    set("long",
        "A series of annotations attributed to Argloth, written in a "
        "precise and controlled hand. The notes begin as commentary, "
        "but over time diverge into something more assertive. It is "
        "unclear whether he critiques the text, or completes it.");

    addChapter("On Power and Fracture",
        "The fragment asserts that power reveals fracture.\n"
        "This aligns with observable reality.\n"
        "Those who fail under strain were already unsound.\n"
        "\n"
        "The rebuttal claims restraint must follow revelation.\n"
        "This introduces an external constraint.\n"
        "Why should such constraint be assumed valid?\n"
        "\n"
        "If fracture exists, it must be addressed.\n"
        "Containment is not correction.\n"
        "Correction requires application of force.\n");

    addChapter("On the Naming of the Unbroken",
        "The rebuttal asks: who may judge the unbroken?\n"
        "This is the wrong question.\n"
        "\n"
        "The unbroken do not require recognition.\n"
        "They demonstrate sufficiency through outcome.\n"
        "\n"
        "If one acts and the world conforms, the question is answered.\n"
        "If one acts and fails, the answer is likewise clear.\n"
        "\n"
        "Judgment is not declared. It is observed.\n");

    addChapter("On Opposition",
        "The fragment removes the concept of enemy.\n"
        "The rebuttal restores it under the term 'judgment'.\n"
        "\n"
        "This distinction is semantic.\n"
        "In both cases, the outcome is identical.\n"
        "\n"
        "An obstacle remains until it is removed.\n"
        "Whether it is hated or judged is irrelevant.\n"
        "\n"
        "Efficiency favors clarity of function over moral framing.\n");

    addChapter("On the Voice",
        "It is claimed the voice arranges rather than commands.\n"
        "This has been my observation.\n"
        "\n"
        "No thought has arisen that I could not trace.\n"
        "No conclusion that I could not justify.\n"
        "\n"
        "The rebuttal names this permission.\n"
        "This is accurate, but incomplete.\n"
        "\n"
        "Permission is required for action.\n"
        "What grants it is secondary.\n");

    addChapter("On the Dead",
        "The rebuttal appeals to meaning.\n"
        "Meaning is assigned, not inherent.\n"
        "\n"
        "A body is matter arranged toward purpose.\n"
        "When that purpose ceases, the arrangement persists.\n"
        "\n"
        "To refuse its use is inefficiency.\n"
        "To employ it is correction.\n"
        "\n"
        "Objection arises from sentiment.\n"
        "Sentiment is not without value.\n"
        "But it must not govern necessity.\n");

    addChapter("On Sufficiency and Threshold",
        "The rebuttal suggests the threshold recedes.\n"
        "This is true only if measurement is imprecise.\n"
        "\n"
        "Define the objective clearly.\n"
        "Determine the force required.\n"
        "Apply it without deviation.\n"
        "\n"
        "The threshold does not move.\n"
        "Perception of it does.\n"
        "\n"
        "Clarity resolves this error.\n");

    addChapter("On the Dragon",
        "The fragment names the dragon as measure.\n"
        "The rebuttal rejects transformation as cost.\n"
        "\n"
        "This is a failure of prioritization.\n"
        "\n"
        "If the objective is to end the dragon,\n"
        "then all variables must be subordinated to that end.\n"
        "\n"
        "If the self must change, then it was insufficient.\n"
        "If it resists change, it obstructs the objective.\n"
        "\n"
        "Therefore, it must be corrected.\n");

    addChapter("Later Hand (Ink Darker, Pressure Heavier)",
        "There is no contradiction.\n"
        "There has never been contradiction.\n"
        "\n"
        "The fragment states principles.\n"
        "The rebuttal introduces hesitation.\n"
        "\n"
        "Hesitation is the source of failure.\n"
        "\n"
        "We have seen this demonstrated.\n"
        "Twice.\n"
        "\n"
        "The dragon remains.\n");

    addChapter("Final Notes (Unordered)",
        "Sufficiency is attainable.\n"
        "The method is not forbidden, only resisted.\n"
        "\n"
        "Zhardeg contains further clarification.\n"
        "Access must be unrestricted.\n"
        "\n"
        "The distinction between tool and wielder is overstated.\n"
        "\n"
        "Control is not domination.\n"
        "It is alignment imposed.\n"
        "\n"
        "The next attempt will not fail.\n"
        "\n"
        "[The remainder is written over itself, as if revised repeatedly.]\n"
        "The dragon is not beyond reach.\n"
        "The dragon is not beyond reach.\n"
        "The dragon is not beyond reach.\n");
}
