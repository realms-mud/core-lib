//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Vanity of Queens");
    set("short", "A slim book with a cracked amethyst inlay");
    set("title", "The Vanity of Queens: Bryleth of Andurath and "
        "the Keepers of the Night");
    set("aliases", ({ "vanity of queens", "bryleth book", "slim book",
        "amethyst book" }));
    set("long", "A slim, elegant book with a cracked amethyst stone "
        "set into its dark leather cover. The text within is "
        "written in two distinct hands, suggesting it was a "
        "collaborative work.");

    addChapter("The Murder of Elonoch III",
        "In Year 315, Bryleth murdered her husband Elonoch III "
        "- tyrant, emperor, and fool. History records this as a "
        "pragmatic coup: the empire was overextended, the war "
        "failing. She sued for peace and was praised for her "
        "wisdom.\n\n"
        "But consider: Elonoch was surrounded by guards, "
        "advisors, and sycophants. How did one woman, however "
        "clever, murder an emperor in his own palace and seize "
        "power without opposition? Unless she possessed "
        "abilities far beyond those of mortal women.");

    addChapter("544 Years of Rule",
        "Bryleth reigned from Year 315 to Year 859. Let the "
        "reader consider what this means. Even the longest-lived "
        "of the maegenstryd rarely surpass three centuries. The "
        "Hillgarathi are immortal, but Bryleth was no elf.\n\n"
        "Throughout her reign, she never aged. Ambassadors who "
        "visited her court decades apart reported the same "
        "woman: pale blue eyes, dark hair, a beauty that "
        "inspired devotion and terror in equal measure.");

    addChapter("The Expulsion from Kharand",
        "In Year 859, Kharand expelled Bryleth. The few "
        "surviving records describe a sudden and violent "
        "upheaval. The people of Kharand rose against her 'as "
        "though a spell had broken.' Bryleth vanished.\n\n"
        "Shortly after her disappearance, Kharand fragmented "
        "into autonomous city-states. It would not recover for "
        "over a thousand years. Whatever hold Bryleth had "
        "maintained over Kharand, its removal left a power "
        "vacuum that nearly destroyed the nation.");

    addChapter("The Keepers of the Night",
        "The Keepers of the Night first appeared in Year 1689 "
        "- some 830 years after Bryleth's disappearance. They "
        "worship a being they call 'the Queen' or 'Her Dark "
        "Majesty,' a goddess of destruction they name "
        "Seilyndria.\n\n"
        "Their hierarchy includes a Nightmaster - always "
        "female, always described as supernaturally beautiful, "
        "always possessing 'pale blue eyes.' The Nightmaster "
        "is said to be the goddess's mortal conduit. Below "
        "her serves a Nightlord and various lesser knights.");

    addChapter("The Connection",
        "We believe Bryleth, Seilyndria, and the 'Queen' of "
        "the Keepers are one and the same being.\n\n"
        "The physical descriptions match precisely. The pale "
        "blue eyes. The terrible beauty. The ability to "
        "inspire devotion and terror. The impossible lifespan. "
        "The Nightmaster's title as 'mortal conduit' suggests "
        "a goddess operating through a chosen vessel - or "
        "wearing a mortal disguise.\n\n"
        "If this is true, then Seilyndria was never truly "
        "imprisoned. She walked among mortals for centuries, "
        "building empires and cults, all while the world "
        "believed her safely bound.");

    addChapter("A Warning",
        "If Seilyndria can take mortal guise, then anyone "
        "might be her vessel. A queen, a prisoner, a scholar, "
        "a beggar. She has demonstrated patience measured in "
        "centuries and a gift for manipulation that borders "
        "on the divine - because it IS divine.\n\n"
        "Trust your instincts. If something seems too "
        "convenient, too perfectly arranged, too neatly "
        "designed to lead you toward a specific action... "
        "consider who benefits.");
}
