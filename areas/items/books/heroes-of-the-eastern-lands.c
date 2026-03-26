//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Heroes of the Eastern Lands");
    set("short", "An illustrated folio with a gilded spine");
    set("title", "Heroes of the Eastern Lands: Notable Figures "
        "in the History of Hillgarath and Eledhel");
    set("aliases", ({ "heroes", "heroes of the eastern lands",
        "illustrated folio", "folio", "gilded book", "book" }));
    set("long", "A large folio with a gilded spine and faded "
        "illustrations. Portraits of notable historical figures "
        "face pages of biographical text. Several pages have been "
        "torn out.");

    addChapter("Arendor, King Eledhen",
        "The restorer of Eneldhor and Ardain, Arendor united the "
        "fractured western realms in Year 0. When Werra of "
        "Hillgarath called for aid against Kharand and Andurath, "
        "Arendor answered with a massive army in Year 43. With "
        "him traveled his friend Halgaladh, son of Halbaladh.\n\n"
        "He returned to war once more in the Orcslayer Wars of "
        "Year 109. Arendor passed in Year 120, having reigned "
        "for over a century.");

    addChapter("Werra of Hillgarath",
        "Son of King Ulric, Werra was sent to Eneldhor as an "
        "envoy in Year 16. He returned upon his father's death "
        "in Year 31 and instituted sweeping legal reforms. His "
        "greatest legacy was the founding of the Werric "
        "Knighthood, the martial order that has defended "
        "Hillgarath for nearly three thousand years.\n\n"
        "Werra was slain in Year 46 during the final battles "
        "against Dervach of Andurath. His knighthood endures.");

    addChapter("Daedrun Kellgaard",
        "A high elf who arrived at Hillgarath Keep in Year 47 "
        "with 400 of his kindred from Echorluin. Daedrun swore "
        "fealty to Ulric II and joined the Werric Knighthood.\n\n"
        "When plague left Hillgarath without an heir in Year 194, "
        "Daedrun served as regent for the child-queen Ainderie. "
        "He served Hillgarath faithfully for millennia. When "
        "plague and war left the throne empty again in Year 2385, "
        "Daedrun assumed the crown as Daedrun Kellgaard I, "
        "founding a dynasty that rules to this day.");

    addChapter("Queen Ainderie",
        "Crowned at age six after plague killed her father and "
        "brothers, Ainderie ruled Hillgarath for 93 years - the "
        "longest reign of any mortal monarch in eastern history. "
        "She forged the great alliance that checked Dor-Temnost's "
        "expansion and personally led her armies into battle.\n\n"
        "She wed Curudil, a high elf companion of Daedrun, who "
        "refused the title of king. Ainderie passed at 99 in "
        "Year 287. Curudil, grief-stricken, passed into the west.");

    addChapter("Bregandil, First King of Eledhel",
        "Nephew of Eldarion, Bregandil led the fleet that "
        "reinforced the eastern alliance in Year 309. He "
        "founded the city of Eledhel in Year 311 and was "
        "crowned its first king by Eldarion himself in 314.\n\n"
        "With him traveled Cuilornir, who founded the Aegis "
        "Guard - the elite force charged with the protection "
        "of Eledhel and its interests. Bregandil's line has "
        "ruled Eledhel through war and peace for over two "
        "thousand years.");

    addChapter("Argloth the Wise",
        "A high elf of immense learning, Argloth was gifted "
        "the Tower of Dhuras in Year 1218 and founded the "
        "Scions of Dhuras. He conquered the Keepers of the "
        "Night's stronghold at Zhardeg in Year 1691.\n\n"
        "His obsession with slaying the dragon Sylthasis "
        "consumed him after his first failed attempt in 1843. "
        "When he finally succeeded in 1964, he had turned to "
        "dark arts - raising the dead and enslaving orcs. He "
        "was slain in the Battle of Mirost in 1965. His fall "
        "remains the Scions' deepest shame.");

    addChapter("The Kings of Eledhel",
        "From Bregandil to the present day, Eledhel has been "
        "ruled by his descendants. Notable among them:\n\n"
        "Finwendil (409) - Lost his father at Utumnadh.\n"
        "Erestel/Ar-Telcontar (667) - A long and peaceful "
        "reign.\n"
        "Arienwen (1765) - First queen. Aided Calendil's "
        "restoration of Hillgarath.\n"
        "Artotis (2228) - Ended the Drell conspiracy with "
        "mercy, granting clemency to the rebels.\n"
        "Ardenel II (2833) - Current king. War has never "
        "ceased during his reign.");
}
