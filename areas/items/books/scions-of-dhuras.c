//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Scions of Dhuras: A History of the Order");
    set("short", "A vellum-bound book embossed with a tower sigil");
    set("title", "The Scions of Dhuras: A History of the Order");
    set("aliases", ({ "scions book", "scions history", "history of the order",
        "vellum book", "tower book", "book" }));
    set("long", "A handsome book bound in pale vellum, embossed with "
        "a silver tower sigil on the front cover. The pages are "
        "crisp and well-maintained, suggesting the Scions took "
        "pride in their own history.");

    addChapter("Foundation",
        "The Scions of Dhuras were founded in Year 1218 when "
        "King Balgamir of Hillgarath gifted the Tower of Dhuras "
        "to Argloth the Wise, a high elf of immense learning. "
        "Argloth was named Governor of Dhuras and charged with "
        "maintaining the tower as a center of scholarship and "
        "martial excellence. The order's name derives from "
        "Dhuras, the ancient fortress upon which the tower "
        "was built.");

    addChapter("Purpose and Philosophy",
        "The Scions blend the warrior's discipline with the "
        "scholar's inquiry. Members train in the art of "
        "channeling arcane energy through their weapons, a "
        "technique Argloth perfected during his centuries of "
        "study. Each Scion chooses a weapon focus - sword, "
        "dagger, axe, mace, hammer, or staff - and pairs it "
        "with an elemental path: flame, ice, lightning, blood, "
        "evocation, or spirit.");

    addChapter("Ranks of the Order",
        "The order observes four ranks:\n\n"
        "Neophyte - New inductees who have demonstrated basic "
        "aptitude in both arms and magic.\n\n"
        "Acolyte - Those who have proven their dedication "
        "through service and study.\n\n"
        "Adept - Experienced members who may take neophytes "
        "under their tutelage.\n\n"
        "Master - The most accomplished Scions, each a "
        "formidable warrior-scholar in their own right.");

    addChapter("The Mana Shield",
        "Central to every Scion's training is the Blessing of "
        "Dhuras, a technique for channeling spell points into a "
        "protective barrier. This mana shield is the order's "
        "signature defense, allowing a Scion to absorb blows "
        "that would fell lesser warriors. Mastery of the shield "
        "is required before advancement beyond Neophyte.");

    addChapter("The Tower of Dhuras",
        "The tower itself predates the order by millennia. It "
        "was originally a watchtower of the ancient kingdom "
        "that preceded Hillgarath. Argloth expanded it into a "
        "proper keep with training halls, a library, forges "
        "for crafting enchanted weapons, and meditation "
        "chambers. The library, in particular, was said to "
        "rival those of the elven realms.\n\n"
        "The tower was razed during the Orcslayer Wars in "
        "Year 109 and rebuilt stronger. It stands to this day "
        "as the order's seat. The Scions' later collapse left "
        "the tower without its keepers and its halls abandoned.");

    addChapter("Argloth's Fall and the Order's Shame",
        "In Year 1843, Argloth's obsession with destroying "
        "the dragon Sylthasis began to consume him. The "
        "elder brothers whispered that he had found something "
        "in Zhardeg when he conquered the Keepers of the "
        "Night - something that whispered to him and fed his "
        "hunger for power.\n\n"
        "When he finally slew Sylthasis in 1964, it was with "
        "dark arts no Scion should wield. He raised the dead "
        "and enslaved orcs. In 1965, the Werric Knights and "
        "dwarves destroyed him.\n\n"
        "The order survived, chastened. Our purpose became "
        "preservation rather than the pursuit of power.");

    addChapter("The Order's Collapse",
        "The Scions of Dhuras no longer operate as an order. "
        "Their tower and halls stand abandoned, and no Circle "
        "of Dhuras or recognized master remains to accept "
        "members. Their records preserve the old discipline: "
        "a Scion needed martial aptitude and the spark of "
        "arcane talent, and could not belong to the Aegis "
        "Guard, a fighters' guild, or a monastic order. Those "
        "who would restore the order must begin without "
        "pretending that its old leaders survived.");
}

/////////////////////////////////////////////////////////////////////////////
public void onChapterRead(object reader, string chapter)
{
    string questPath = "/areas/minlach/quests/scions-restoration.c";

    if (objectp(reader) && function_exists("beginQuest", reader) &&
        reader->beginQuest(questPath))
    {
        object quest = load_object(questPath);
        reader->onStateChanged(quest, reader->questState(questPath));
        tell_object(reader, "Your journal records a new undertaking: "
            "help Renveth restore the Scions of Dhuras.\n");
    }
}
