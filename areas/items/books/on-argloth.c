//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "On the Matter of Argloth");
    set("short", "A book titled 'On the Matter of Argloth'");
    set("title",
        "On the Matter of Argloth: His Rise, His Obsession, and His Fall");
    set("aliases",
        ({ "argloth treatise", "dhuras account", "zhardeg record",
            "book", "treatise", "account" }));
    set("long",
        "A sober account composed by the Scions of Dhuras after the death "
        "of their founder. It seeks neither to praise nor condemn, but to "
        "understand how wisdom became obsession, and how purpose became ruin.");

    addChapter("Of the Man He Was",
        "Argloth came to Dhuras in wisdom and in restraint.\n"
        "He was not yet the man we would later fear to name.\n"
        "His learning was vast, yet ordered and disciplined.\n"
        "He sought knowledge, but not dominion.\n"
        "In those days, he spoke often of balance and restraint.\n"
        "He warned that power ungoverned was a danger to all.\n"
        "We believed him, for he believed it himself.\n"
        "The tower grew under his guidance, stone and mind alike.\n"
        "We were his students, and he our measure.\n"
        "It is necessary to remember this, lest we lie to ourselves.\n");

    addChapter("Of Zhardeg and the First Turning",
        "When the Keepers of the Night rose, Argloth did not hesitate.\n"
        "He struck their stronghold and broke them utterly.\n"
        "Zhardeg was taken, and with it, their hidden works.\n"
        "It is here that the records grow uncertain.\n"
        "Some say he found texts; others, an object of power.\n"
        "A few speak of a voice, though none agree on its nature.\n"
        "Argloth spoke little of what he claimed in that place.\n"
        "Yet after Zhardeg, he listened more than he spoke.\n"
        "And when he spoke, it was often of necessity.\n"
        "Not of what should be done, but of what must.\n");

    addChapter("Of the Dragon and the Wound",
        "When Sylthasis destroyed Mirost, all lands were shaken.\n"
        "Argloth was among those who would answer that ruin.\n"
        "In the year of his first attempt, he marched in strength.\n"
        "His host was broken, and his purpose shattered.\n"
        "He survived, though many greater than we did not.\n"
        "After this, a change is plainly recorded.\n"
        "He spoke no longer of balance, only of sufficiency.\n"
        "Power became not a danger, but a requirement.\n"
        "The dragon was no longer a foe to be faced.\n"
        "It became a thing that must be ended, at any cost.\n");

    addChapter("Of Obsession",
        "In the years that followed, Argloth withdrew from counsel.\n"
        "He studied in isolation, gathering works long forbidden.\n"
        "He returned often to Zhardeg, and tarried there.\n"
        "Some among us claimed to hear voices in his absence.\n"
        "Others dismissed such claims as fear or envy.\n"
        "We did not act. This is our failure.\n"
        "When he spoke again, it was with certainty, not wisdom.\n"
        "He no longer questioned. He declared.\n"
        "And we, who had learned from him, did not resist him.\n");

    addChapter("Of the Second Failure",
        "In the year 1888, he marched again against Sylthasis.\n"
        "His preparations were greater, his knowledge deeper.\n"
        "Yet the outcome did not change.\n"
        "Again, his forces were broken before the dragon.\n"
        "Again, he survived where others did not.\n"
        "It is said he did not speak for many days thereafter.\n"
        "When he did, it was only this:\n"
        "'There is more yet to learn.'\n"
        "We did not then understand what that would mean.\n");

    addChapter("Of the Final Transformation",
        "By the time of his last campaign, he was not as before.\n"
        "He commanded not only men, but creatures once opposed.\n"
        "Orcs marched beneath his will, bound by means unknown.\n"
        "He spoke of unity through mastery, not accord.\n"
        "What he had taken from Zhardeg had taken hold in him.\n"
        "Whether tool or master, we cannot say.\n"
        "Only that Argloth no longer stood alone within himself.\n");

    addChapter("Of Victory and Its Price",
        "In 1964, Sylthasis fell.\n"
        "This is fact, and cannot be denied.\n"
        "Argloth achieved what none before him could.\n"
        "Yet the manner of that victory is our condemnation.\n"
        "The dragon did not merely die; it was bound.\n"
        "Its corpse was made servant to his will.\n"
        "And worse, those who had fallen before it rose again.\n"
        "Not as they were, but as instruments.\n"
        "Thus was victory purchased, and thus was it defiled.\n");

    addChapter("Of the Battle of Mirost",
        "The dwarves would not suffer this.\n"
        "Nor would Hillgarath endure what had been done.\n"
        "They came in force, and the field was joined.\n"
        "Those who fought speak of horrors beyond measure.\n"
        "Dwarves turned against their own kin.\n"
        "The dead moved where they had once lain still.\n"
        "And above it all, Argloth stood, unyielding.\n"
        "He was slain, but not before the cost was paid.\n"
        "Victory was theirs, but no triumph followed.\n");

    addChapter("Of Aftermath and Silence",
        "Mirost was abandoned, though it had been reclaimed.\n"
        "The dwarves declared it tainted beyond redemption.\n"
        "We did not contest this judgment.\n"
        "The halls of Dhuras grew quiet in those days.\n"
        "We had lost not only our master, but our purpose.\n"
        "For we had followed him, and failed to see.\n"
        "Or seen, and failed to act.\n"
        "These are not different things.\n");

    addChapter("Conclusion",
        "Let it not be said that Argloth sought ruin.\n"
        "He sought victory over a terror that had broken the world.\n"
        "But in seeking power without limit, he became its servant.\n"
        "This is the lesson we record, and preserve.\n"
        "Knowledge is not virtue. Power is not purpose.\n"
        "And the road to ruin is not walked in darkness alone.\n"
        "It is walked in certainty.\n"
        "[A marginal note: 'We keep the tower as a warning.']\n");
}
