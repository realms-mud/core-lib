//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Werric Knighthood");
    set("short", "A book bound in red-dyed leather");
    set("title", "The Werric Knighthood: Shield of Hillgarath");
    set("aliases", ({ "werric", "werric knighthood", "red book",
        "knighthood", "shield of hillgarath" }));
    set("long", "A handsome book bound in red-dyed leather, stamped "
        "with the crossed-swords emblem of the Werric Knighthood. "
        "It appears to be a combination of history and recruiting "
        "pamphlet.");

    addChapter("The Founding",
        "The Werric Knighthood was founded by King Werra of "
        "Hillgarath in Year 31. Werra had spent fifteen years "
        "in Eneldhor and returned with a vision: a standing "
        "order of elite warriors bound by oath to defend "
        "Hillgarath and its people.\n\n"
        "The name 'Werric' derives from Werra himself. To be "
        "called Werric is to embody his ideals: courage, "
        "loyalty, and the willingness to stand when others "
        "flee.");

    addChapter("Notable Campaigns",
        "The Werrics have fought in every major conflict of "
        "the eastern lands:\n\n"
        "Year 37: Retook Delerath with the dwarves of Mirost.\n"
        "Year 409: Fought at Utumnadh. Lost their king.\n"
        "Year 1816: Restored King Calendil after civil war.\n"
        "Year 1965: Destroyed Argloth at the Battle of Mirost.\n"
        "Year 2249: Broke the siege of Celebduil.\n"
        "Year 2941: Annihilated the orc strongholds.");

    addChapter("Daedrun and the Hillgarathi",
        "In Year 47, the high elf Daedrun arrived at "
        "Hillgarath with 400 of his kindred and swore fealty "
        "to the crown. He joined the Werric Knighthood and "
        "brought with him centuries of elven martial wisdom.\n\n"
        "Daedrun served as regent for Queen Ainderie and later "
        "assumed the throne himself as Daedrun Kellgaard I. "
        "His family has ruled Hillgarath since Year 2385. "
        "The Kellgaard line is uniquely both Hillgarathi and Werric.");

    addChapter("The Pact of Serach",
        "In Year 2359, Eledhel and Hillgarath signed the Pact "
        "of Serach, formalizing their mutual defense. Each "
        "nation pledged army divisions and knight brigades to "
        "the other's defense.\n\n"
        "The pact was born of necessity - both nations faced "
        "threats from Kharand, Andurath, and the ever-present "
        "orcish menace. It remains the cornerstone of eastern "
        "security to this day.");

    addChapter("The Drell Conspiracy",
        "In Year 2227, King Areladur of Eledhel fell in battle "
        "with Kharand. Torma Drell contested the rightful heir "
        "Artotis, plunging Eledhel into civil war.\n\n"
        "Artotis destroyed Drell's army and slew both Torma and "
        "his son. In an act of extraordinary mercy, he granted "
        "clemency to the surviving Drell family. Lady Drell "
        "moved to Ethyl Tirath and changed her name to Belethon. "
        "The Belethon family has served Eledhel loyally since.");

    addChapter("Sir Kellgaard of Hillgarath",
        "Among the most formidable of the Werric Knights is "
        "the current lord of Hillgarath - Sir Kellgaard, a "
        "Hillgarathi of ancient lineage who has served the crown "
        "since the founding of the Kellgaard dynasty.\n\n"
        "He is known throughout the eastern lands as a warrior "
        "of extraordinary skill. Even the servants of darkness "
        "fear to face him in open combat. His longevity and "
        "experience make him one of the most dangerous swords "
        "in the world.");
}
