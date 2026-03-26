//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Reply from the Circle of Dhuras");
    set("short", "A concerned response to Argloth's letter");
    set("title",
        "A Letter from the Circle of Dhuras to Argloth");
    set("aliases",
        ({ "dhuras reply", "circle correspondence", "argloth response",
            "letter", "response", "concerned response", 
            "a concerned response to argloth's letter", 
            "concerned response to argloth's letter" }));
    set("long",
        "A preserved response written by the Circle of Dhuras to Argloth. "
        "The tone is measured, yet a deep undercurrent of alarm runs through "
        "the writing. Marginalia suggests it was read repeatedly, as if "
        "to find a path to reach him.");

    addChapter("The Reply",
        "To Argloth, whose wisdom has guided us for decades,\n"
        "\n"
        "We have read your words with utmost care. Your reasoning is sound\n"
        "and your eloquence unmatched, yet we must speak plainly where\n"
        "our concern outweighs our usual restraint.\n"
        "\n"
        "We are aware of the failures and threats that weigh heavily upon\n"
        "you. The dragon Sylthasis endures, and the ruins of Mirost cry\n"
        "out for redress. We do not ask that you ignore these truths.\n"
        "\n"
        "Yet we fear the path you now contemplate. Knowledge pursued alone,\n"
        "without counsel, may lead to ruin that no skill or courage can\n"
        "undo. Isolation has not yet claimed your wisdom, but it edges close.\n"
        "\n"
        "You ask whether inaction is worse than the risks of deeper study.\n"
        "We cannot answer this for you, but we beg you to remember that\n"
        "measured action, guided by fellowship, has long been our shield.\n");
    addChapter("The Reply (cont'd)",
        "Consider carefully the cost of pursuing forces whose nature you\n"
        "may not yet fully understand. We have long admired your courage\n"
        "and your intellect. To lose these to obsession would be a loss\n"
        "greater than any failure in battle.\n"
        "\n"
        "Your dedication to purpose is unquestioned. Our plea is not for\n"
        "doubt, but for restraint. Step back, if only for a moment, and\n"
        "allow us to aid you. Let us share the burden, as we have done\n"
        "through countless trials.\n"
        "\n"
        "The dangers you face are real. The shadows in Zhardeg are\n"
        "older than any of us. We beseech you, Argloth, let reason\n"
        "guide action, and let fellowship temper ambition.\n"
        "\n"
        "We remain your friends, your peers, and your loyal council.\n"
        "We ask only that you remember what has made you wise, and\n"
        "not what tempts you toward greatness alone.\n"
        "\n"
        "- The Circle of Dhuras\n"
        "\n"
        "[A marginal note, perhaps in Argloth's own hand: 'I read and nod.\n"
        "But they do not yet know what I have seen in Zhardeg.']\n");
}
