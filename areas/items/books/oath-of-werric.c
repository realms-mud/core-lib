//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Oath of Werric");
    set("short", "a formal volume titled 'The Oath of Werric'");
    set("title",
        "The Oath of Werric: The Induction of Sir Uhrdalen");
    set("aliases",
        ({ "werric oath", "uhrdalen chronicle", "knight book",
           "oath", "chronicle", "book", "formal volume", "volume" }));
    set("long",
        "A formal chronicle of the Werric Order. Its measured tone "
        "details the induction and early service of Sir Uhrdalen. "
        "Subtle irregularities in the script suggest doubt beneath "
        "unyielding doctrine.");

    addChapter("Induction",
        "It is said among the uninitiated that strength is born of will.\n"
        "\n"
        "This is false.\n"
        "\n"
        "Strength is not will. Strength is the surrender of will,\n"
        "refined and given wholly to purpose. A blade that chooses\n"
        "its own path is a danger. A blade that obeys becomes an\n"
        "instrument of perfection.\n"
        "\n"
        "Thus are the Knights of Werric forged.\n"
        "\n"
        "Uhrdalen was not remarkable as a child. He was not the\n"
        "strongest, nor the swiftest. He was not marked as brilliant.\n"
        "If anything, he was known for stillness.\n"
        "\n"
        "Where others questioned, he listened.\n"
        "Where others resisted, he yielded.\n"
        "\n"
        "And in this, the Order saw promise.\n");

    addChapter("The Oath",
        "On the day of induction, the novices were brought beneath\n"
        "the basalt arches of the Inner Sanctum. No light touched\n"
        "that place without leave. No voice rose unbidden.\n"
        "\n"
        "They were told:\n"
        "\n"
        "You are not here to become great.\n"
        "You are here to become useful.\n"
        "\n"
        "Some faltered. One wept. Another spoke and was removed.\n"
        "A third hesitated when the blade was placed in his hand.\n"
        "\n"
        "Uhrdalen did none of these things.\n"
        "\n"
        "He stepped forward. He knelt. He did not look at the blade.\n"
        "\n"
        "The Oath was not long, but it was absolute.\n"
        "\n"
        "I am not my will.\n"
        "I am not my fear.\n"
        "I am not my doubt.\n"
        "\n"
        "I am the will given to me.\n"
        "I am the fear I am commanded to face.\n"
        "I am the doubt I am ordered to silence.\n"
        "\n"
        "I obey.\n"
        "\n"
        "Uhrdalen spoke the words as though they had always been true.\n");

    addChapter("Training",
        "Training stripped away what little remained. Names were\n"
        "seldom used. Identity was inefficiency. The body was honed.\n"
        "The mind was sharpened. The spirit was narrowed.\n"
        "\n"
        "Pain was instruction.\n"
        "Silence was expectation.\n"
        "Failure was correction.\n"
        "\n"
        "When pressed beyond endurance, they were told:\n"
        "You are not tired. You are resisting.\n"
        "\n"
        "When fear took hold:\n"
        "Fear is a choice. Choose differently.\n"
        "\n"
        "When doubt surfaced:\n"
        "Doubt is disobedience made manifest.\n"
        "\n"
        "Uhrdalen learned quickly. Not through excellence, but\n"
        "through absence of resistance.\n"
        "\n"
        "Weakness and strength became one truth.\n"
        "To resist was weakness.\n"
        "To yield was strength.\n");

    addChapter("A Marginal Note",
        "There is one passage preserved in the margin of a later\n"
        "transcription. The hand is steady, but the ink is pressed\n"
        "deeply into the page.\n"
        "\n"
        "If one does not choose, can one be said to be strong?\n"
        "Or is strength merely the absence of choice?\n"
        "\n"
        "No answer is given.\n"
        "No correction follows.\n"
        "\n"
        "The line remains.\n");

    addChapter("The Charge",
        "In the years that followed, Uhrdalen rose within the Order.\n"
        "He did not seek command. Thus, it was given. He did not\n"
        "question judgment. Thus, he was entrusted to enact it.\n"
        "\n"
        "He did not waver.\n"
        "\n"
        "Thus, he was sent where wavering meant failure.\n"
        "\n"
        "It was then that his name became tied to a matter of\n"
        "consequence.\n"
        "\n"
        "Bryleth.\n"
        "\n"
        "She was recorded as a deviation. A fracture in the order\n"
        "of will and obedience. Where she walked, structure weakened.\n"
        "Where she spoke, certainty faltered.\n"
        "\n"
        "Such things could not be permitted.\n"
        "\n"
        "The command was given without ceremony:\n"
        "\n"
        "Find her.\n"
        "Bind her.\n"
        "End what she represents.\n"
        "\n"
        "Uhrdalen accepted as he had all things.\n"
        "\n"
        "Without question.\n");
}
