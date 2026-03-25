//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Fall of Dor-Temnost");
    set("short", "A book on the fall of Dor-Temnost");
    set("title",
        "The Fall of Dor-Temnost: A Chronicle of Ruin");
    set("aliases",
        ({ "fall of dor-temnost", "temnost fall", "iron ruin", "book" }));
    set("long",
        "A grave and measured work, its tone subdued and heavy. "
        "It speaks of pride grown too great, of cruelty returned "
        "upon itself, and of a realm that could not endure.");

    addChapter("The Failing Crown",
        "In the later years of Elonoch the third,\n"
        "The court grew thin, though walls still stood high.\n"
        "Where once were counselors of tempered thought,\n"
        "Now flatterers and fearful men remained.\n"
        "The emperor spoke, yet few would answer true,\n"
        "For truth had long since fallen out of favor.\n"
        "'All stands secure,' thus did he oft declare,\n"
        "'For none may match the strength we now command.'\n"
        "Yet in the streets, another tale was told,\n"
        "Of hunger, levy, and unending war.\n"
        "So did the crown sit heavy on his brow,\n"
        "Though he perceived it not, nor sought to know.\n");

    addChapter("The Breaking of the Provinces",
        "Far from the court, the outer lands grew restless,\n"
        "Where tribute pressed and little aid returned.\n"
        "Old loyalties, once bound by oath and fear,\n"
        "Began to fray beneath the constant strain.\n"
        "A lord of Rhundaur spoke in secret hall:\n"
        "'We bleed for masters who remember not.\n"
        "Why should we stand when none now stand for us?'\n"
        "So spoke he, and many gave assent.\n"
        "In shadow first, then open defiance came,\n"
        "As garrisons found gates no longer theirs.\n"
        "Thus did the realm, though vast upon the map,\n"
        "Begin to shrink where will no longer held.\n");

    addChapter("The Emperor’s Answer",
        "When word was brought of lands that slipped his grasp,\n"
        "Elonoch rose in fury from his throne.\n"
        "'Shall dust defy the hand that raised it high?'\n"
        "So spoke the lord of Dor-Temnost in wrath.\n"
        "'Send forth the legions—burn what will not bow;\n"
        "Let ruin teach what mercy could not hold.'\n"
        "Thus was his will made iron law once more,\n"
        "And fire went forth where doubt had taken root.\n"
        "Yet every city broken in his name\n"
        "Removed another stone from his own wall.\n"
        "For fear compels, but cannot long sustain,\n"
        "And ash breeds little loyalty in men.\n");

    addChapter("The Eastern Advance",
        "While thus the empire turned upon itself,\n"
        "The eastern host advanced with steady hand.\n"
        "From Eledhel came strength both new and sure,\n"
        "And with it hope that had not been before.\n"
        "A captain spoke before the gathered ranks:\n"
        "'We fight not only to unmake a throne,\n"
        "But to ensure it rises not again.'\n"
        "So moved they on, not swift, but resolute,\n"
        "Taking each hold and keeping what was won.\n"
        "And where they passed, the people did not flee,\n"
        "But watched, and weighed, and often chose their side.\n");

    addChapter("The Last Mustering",
        "At Tirnost, last and greatest of his seats,\n"
        "The emperor gathered what remained to him.\n"
        "There stood the remnants of his former might,\n"
        "Though fewer far than in the elder days.\n"
        "Before them all, Elonoch raised his voice:\n"
        "'Have you grown soft, that lesser men advance?\n"
        "We are the fire that others fear to face!'\n"
        "So spoke he, yet the answering cry was thin.\n"
        "For many there remembered fields long lost,\n"
        "And brothers fallen in forgotten wars.\n"
        "Still were they bound, by oath or else by fear,\n"
        "To stand and meet the end that now drew near.\n");

    addChapter("The Fall of Tirnost",
        "The battle came before the city walls,\n"
        "And long it raged with neither side giving.\n"
        "Steel answered steel, and fire was met with fire,\n"
        "Till even the stones seemed wearied by the strife.\n"
        "Then from the east the final breach was made,\n"
        "And through it poured the host that would not break.\n"
        "A voice was heard amid the failing lines:\n"
        "'The day is lost—save what you may and flee!'\n"
        "So spread the word, and order turned to rout.\n"
        "The gates were taken, and the banners cast,\n"
        "And Tirnost fell as others fell before.\n"
        "Thus ended what had once seemed unassailable.\n");

    addChapter("The Emperor in Exile",
        "Elonoch fled from that forsaken field,\n"
        "And sought new strength in Khendrus far away.\n"
        "Yet though he claimed a throne in foreign stone,\n"
        "The weight of empire no longer followed him.\n"
        "Those who remained were but a shadowed court,\n"
        "A memory clinging to a vanished form.\n"
        "He spoke still as though all were his to rule:\n"
        "'This is no end, but only passing trial.'\n"
        "Yet none could fail to see what had been lost,\n"
        "Nor that no force remained to win it back.\n");

    addChapter("The End of Dor-Temnost",
        "So passed the realm that once had spanned the lands,\n"
        "Not in a single blow, but many wounds.\n"
        "What war began, its own hand finished well,\n"
        "For pride had sown what ruin came to reap.\n"
        "Let those who hear take heed of what befell:\n"
        "That strength without restraint devours itself.\n"
        "No wall stands long when all within is hollow,\n"
        "Nor crown endures when fear alone sustains.\n"
        "So ends the line of Dor-Temnost in ash,\n"
        "Its name a warning carried down the years.\n");
}
