//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The March and Maneuver");
    set("short", "A book titled 'The March and Maneuver'");
    set("title", "The March and Maneuver: Being a True Account of the Turning "
        "of the Tide");
    set("aliases", ({ "march and maneuver", "tide chronicle", "tide",
        "campaign account", "book" }));
    set("long", "A compact codex, written in a steady and practiced hand. "
        "It does not delight in ornament, but in memory: of marches "
        "measured, of ground taken and held, and of those decisions by "
        "which Ulric and Arendor bent fortune to their cause.");

    addChapter("Preface",
        "I set these matters down not as a poet, but as one who marched "
        "beneath Ulric and bore witness to those events by which the tide "
        "was turned. Let no reader seek here embellishment, for I have "
        "preferred clarity to praise. I record what was done, and, where I "
        "am able, why it was done; for in such knowledge lies the profit of "
        "those who would command after us. If rumor is absent, it is not "
        "from ignorance, but from judgment.");

    addChapter("On Mustering Forces",
        "When the call to arms was given, Werra did not rely upon chance, "
        "but upon the ancient bonds of oath and duty that bind the "
        "countryside. Messengers were sent forth, and the reeves made "
        "their tallies known. Some came on foot with shield and spear, "
        "others mounted where horseflesh could be spared. Thus the host "
        "was shaped not only by will, but by what the land itself could "
        "provide; and from this arose the manner in which it might fight.");

    addChapter("On Holding a Gap",
        "There is wisdom in narrow places, for there numbers are made "
        "equal. Ulric perceived this and set his strongest shields where "
        "the ground would constrain the foe. Timber was cut and driven "
        "into the earth, and the approaches cleared, so that no man might "
        "come unseen. There the enemy were compelled into tight ranks, "
        "where discipline, not multitude, decided the contest.");

    addChapter("On Logistics and Water",
        "An army does not move by courage alone, but by bread and water. "
        "The Lonis river served as both guide and lifeline, and upon it "
        "depended much of our endurance. Boats were set to carry stores "
        "when roads failed, and grain was laid aside in friendly places "
        "against lean days. In this manner, Ulric ensured that the army "
        "should not hunger before it fought.");

    addChapter("On Intelligence",
        "No commander sees with his own eyes alone. At dawn and dusk, "
        "scouts returned with word of the enemy, and those whose reports "
        "proved true were trusted above all others. Guesswork was set "
        "aside in favor of what could be counted and known. Thus small "
        "bands, well-acquainted with the land, served better than many "
        "who wandered without knowledge.");

    addChapter("On Night Operations",
        "When darkness fell, it did not bring rest to all. Chosen men went "
        "forth in silence to trouble the enemy, cutting their supply and "
        "harrying those who strayed. Such work required not only courage, "
        "but restraint; for a single misstep could turn stealth into ruin. "
        "Yet when it was well done, it weighed upon the enemy's spirit as "
        "much as any battle fought by day.");

    addChapter("On River Fords and Defense",
        "At the ford of the Lonis, Ulric made ready not only for passage, "
        "but for contest. Stakes were hidden beneath the water, and the "
        "approach made treacherous. Archers held the higher ground, while "
        "a reserve stood watchful behind. For it is often the unseen hand "
        "of the reserve that determines whether a line stands or breaks.");

    addChapter("On Command and Presence",
        "It was the custom of Ulric to be seen among his men, not as one "
        "reckless of danger, but as one who understood its measure. His "
        "presence gave heart to the uncertain, while his captains were "
        "entrusted with clear authority. Thus order was maintained, and "
        "action taken without delay when the moment required it.");

    addChapter("On Cavalry Tactics",
        "Horsemen, when rightly used, are as a hammer against a weakened "
        "line. Ulric did not waste them upon broken ground, but held them "
        "for those moments when the enemy wavered. Then they struck in "
        "tight formation, breaking through before withdrawing again, lest "
        "they be surrounded. In this way, they achieved much while risking "
        "little.");

    addChapter("On The Turning Point",
        "The enemy, seeking advantage, stretched their line too far in "
        "hope of encircling us. Ulric, who had kept men in readiness, "
        "fell upon this extended flank with sudden force. What followed "
        "was not a rout at once, but a yielding that spread, until their "
        "withdrawal became inevitable. Thus a single well-timed stroke "
        "undid a greater design.");

    addChapter("On Diplomacy and Alliances",
        "Not all victories are won by steel alone. The coming of Arendor "
        "altered the balance, as timely aid often does. Moreover, Eldarion "
        "made use of the sea, moving men with a swiftness the enemy could "
        "not match. From this it may be learned that clear terms and swift "
        "agreement are as valuable as any stratagem.");

    addChapter("On The Aftermath",
        "When the fighting ceased, Ulric did not permit disorder to take "
        "root. Garrisons were set, roads secured, and accords made with "
        "those who dwelt in the land. For it is not enough to win a battle; "
        "one must also hold what has been gained, and govern it with care.");

    addChapter("On Training and Discipline",
        "It was evident that those who had been well-trained stood firm "
        "where others faltered. Ulric placed great emphasis upon cohesion, "
        "teaching men to act as one rather than as many. In this lay their "
        "strength, for unity endures where numbers alone cannot.");

    addChapter("On Use of Local Forces",
        "The men of the region, though not equal in all things to seasoned "
        "soldiers, possessed knowledge no outsider could claim. Ulric "
        "employed them where this knowledge was of greatest worth, while "
        "reserving his veterans for the main struggle. Thus each served "
        "according to his strength.");

    addChapter("Appendix: Muster Rolls",
        "For those who value reckoning: the host numbered twelve hundred "
        "with shield, three hundred light horse, and two hundred "
        "skirmishers. To these were added engineers, keepers of supply, "
        "and scouts. Their sustenance was measured carefully, that none "
        "should want before the contest was decided.");
}
