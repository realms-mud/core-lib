//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dragons and Dark Powers");
    set("short", "A scorched book with claw marks on the cover");
    set("title", "Dragons and Dark Powers: Utumnadh and the "
        "Terrors That Issue Forth");
    set("aliases", ({ "dragons", "dragons and dark powers",
        "scorched book", "claw book", "book" }));
    set("long", "A book that appears to have survived a fire. The "
        "leather cover bears what look like claw marks. Despite "
        "the damage, the text within is largely intact.");

    addChapter("The Shadow of Utumnadh",
        "Utumnadh has been a source of evil since before the "
        "founding of the eastern kingdoms. In Year 84, smoke "
        "first belched from its depths and orcs began to "
        "multiply in the surrounding mountains. By Year 108, "
        "those orcs had sacked Arnost and slaughtered its "
        "240,000 inhabitants.\n\n"
        "The Orcslayer Wars that followed required the combined "
        "might of Hillgarath, Mirost, and Eneldhor to quell.");

    addChapter("The Battle of Utumnadh, Year 409",
        "In Year 406, a dark force - believed to be one of "
        "the fallen gods - established power within Utumnadh. "
        "The alliance formulated plans to attack.\n\n"
        "The battle in Year 409 was victorious but devastating. "
        "Three kings fell: the kings of Mirost, Hillgarath, and "
        "Eledhel. The menace within Utumnadh grew silent, but "
        "the cost was immense. This battle shaped the political "
        "landscape of the east for centuries to come.");

    addChapter("Ilzhagash and Sylthasis",
        "In Year 1692, two dragons issued from Utumnadh. The "
        "first, Ilzhagash, attacked Mirost and was slain by "
        "the dwarves. The second, Sylthasis, proved far more "
        "terrible.\n\n"
        "In Year 1693, Sylthasis destroyed Arnost and overran "
        "Mirost itself. The dwarven kingdom fell. Its survivors "
        "fled to Hillgarath and Khazurath. For nearly three "
        "hundred years, Sylthasis ruled the ruins of Mirost "
        "unchallenged.");

    addChapter("Argloth's Obsession",
        "Argloth the Wise first challenged Sylthasis in Year "
        "1843. His army was utterly destroyed, though he "
        "survived. From this point forward, those who knew him "
        "noted a marked change in his personality. He became "
        "consumed with the desire for power.\n\n"
        "He tried again in Year 1888 and failed again. But "
        "he did not stop. He began to study darker arts, to "
        "seek forbidden knowledge, to make bargains that no "
        "scholar of good conscience would entertain.");

    addChapter("The Fall of Mirost, Year 1964",
        "In Year 1964, Argloth finally slew Sylthasis. But "
        "his victory was a perversion. He had enlisted orcs "
        "into his service. Worse, he had raised the dead - "
        "including the corpse of Sylthasis itself and many "
        "of the dwarves slain when Mirost first fell.\n\n"
        "He declared himself lord of Mirost. The dwarves and "
        "the Werric Knights marched against him.");

    addChapter("The Battle of Mirost, Year 1965",
        "The Werric Knights and the dwarven remnants of Mirost "
        "waged a terrible battle against Argloth's forces. "
        "Argloth was slain and his armies scattered.\n\n"
        "But Mirost was abandoned. The dwarves sensed that the "
        "halls were tainted beyond cleansing. To this day, "
        "Mirost remains empty - a monument to the corrupting "
        "power of obsession and the terrible cost of victory "
        "won through dark means.");

    addChapter("The Orcs Resurface",
        "Though the dragon threat ended in 1965, the orcs did "
        "not vanish. They fled Mirost in Year 2012, descending "
        "on Hillgarath. Rumors spread of undead hordes in the "
        "mountains - Argloth's legacy, perhaps, or something "
        "worse stirring in Utumnadh's depths.\n\n"
        "The Battle of Zhaghadel in Years 2671-2674 silenced "
        "the orcs for two centuries. But they returned in Year "
        "2870, and in Year 2940 they besieged Ethyl Tirath. "
        "Whatever dwells within Utumnadh, it is not done with "
        "the world.");
}
