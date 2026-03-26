//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Fragment from Zhardeg");
    set("short", "A partial and unsettling text");
    set("title",
        "Fragment from Zhardeg: Recovered from the Lower Vaults");
    set("aliases",
        ({ "zhardeg fragment", "keeper text", "whispering page", "text",
            "book", "partial text" , "a partial and unsettling text",
            "unsettling text" }));
    set("long",
        "A damaged and incomplete text recovered from the ruins of "
        "Zhardeg. The script is inconsistent, as though written by "
        "multiple hands or at different times. Several passages appear "
        "to contradict one another. Marginal notes warn against extended study.");

    addChapter("The First Leaf (Damaged)",
        "Power is not taken. It is recognized.\n"
        "Those who grasp at it find only ash.\n"
        "Those who see it clearly need not reach.\n"
        "\n"
        "You have been taught that power corrupts.\n"
        "This is imprecise.\n"
        "Power reveals the fracture already present.\n"
        "Therefore, the unbroken may wield it without cost.\n"
        "\n"
        "[The remainder of the page is charred beyond reading.]\n");

    addChapter("On the Nature of Opposition",
        "There are no enemies, only impediments.\n"
        "An impediment is not evil. It is merely present.\n"
        "To remove it is not cruelty, but correction.\n"
        "\n"
        "Consider the beast that burns the fields.\n"
        "You name it destroyer.\n"
        "Yet it acts in accordance with its nature.\n"
        "Would you condemn the flame for rising?\n"
        "\n"
        "Correction, then, is not hatred.\n"
        "It is alignment.\n");

    addChapter("A Marginal Hand (Uncertain Origin)",
        "This passage is cited often among the inner circle.\n"
        "It is used to justify necessary acts.\n"
        "I record here that I do not agree.\n"
        "Something in this reasoning removes the weight of choice.\n"
        "If there is no enemy, there is no restraint.\n"
        "If there is no restraint, what remains of us?\n");

    addChapter("On the Voice",
        "You ask if the power speaks.\n"
        "It does not speak as you understand speech.\n"
        "It arranges what is already within you.\n"
        "\n"
        "A thought placed beside another thought.\n"
        "A certainty placed beside a doubt.\n"
        "In time, the arrangement becomes inevitable.\n"
        "\n"
        "You will say: 'I chose this.'\n"
        "And you will be correct.\n"
        "\n"
        "You will also be incorrect.\n");

    addChapter("The Question of the Dead",
        "What is a body, once the animating force departs?\n"
        "You say: sacred, inviolate, to be returned to earth.\n"
        "This is custom, not law.\n"
        "\n"
        "If the pattern may be restored, is it not waste to refuse?\n"
        "If the will may be imposed, is it not strength to do so?\n"
        "\n"
        "You recoil at this.\n"
        "That is expected.\n"
        "Recoil is the first defense of an unexamined belief.\n");

    addChapter("Second Marginal Note (Faded)",
        "We sealed this section once. It was reopened.\n"
        "Argloth read here for many hours.\n"
        "When he emerged, he did not speak to us.\n"
        "He only asked for access to the lower vaults.\n"
        "We granted it.\n"
        "This was our error.\n");

    addChapter("On Sufficiency",
        "There exists a threshold beyond which opposition ceases.\n"
        "Below it, you struggle and fail.\n"
        "Above it, the world conforms.\n"
        "\n"
        "You name this tyranny.\n"
        "This is a moral framing, not a functional one.\n"
        "\n"
        "Consider instead: sufficiency.\n"
        "Enough force, enough will, enough clarity.\n"
        "Not excess. Not cruelty.\n"
        "Only enough.\n"
        "\n"
        "Find the threshold, and cross it.\n");

    addChapter("Final Fragment",
        "[This section is fragmented and difficult to follow.]\n"
        "The dragon is not the end.\n"
        "The dragon is the measure.\n"
        "\n"
        "If you cannot overcome it, you are not yet sufficient.\n"
        "If you overcome it and remain unchanged, you have failed.\n"
        "\n"
        "To master the greater force, one must become...\n"
        "[text missing]\n"
        "\n"
        "Do not fear the transformation.\n"
        "Fear only inadequacy.\n");
}
