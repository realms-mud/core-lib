//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Lay of Bregandil");
    set("short", "A book titled 'The Lay of Bregandil'");
    set("title",
        "The Lay of Bregandil: The Crown Beyond the River");
    set("aliases",
        ({ "bregandil", "lay of bregandil", "eastward crown",
            "book", "song", "lay" }));
    set("long",
        "A finely kept codex, its verses more fervent than most. "
        "It tells not of armies alone, but of a single will that "
        "crossed the river and raised a kingdom from war.");

    addChapter("The Oath of Departure",
        "Hear now of Bregandil, bold among princes,\n"
        "Sister's son to Eldarion the steadfast king.\n"
        "When war was kindled on the eastern shore,\n"
        "He stood before his kin and made this oath:\n"
        "'I will not linger where the walls are sure,\n"
        "Nor take my ease while others bleed afar.\n"
        "Across the Lonis shall my banner pass,\n"
        "And there I claim what fate has left unruled.'\n"
        "So spoke Bregandil before the gathered court,\n"
        "And many marveled at his fearless tongue.\n"
        "Cuilornir then, his companion long and true,\n"
        "Stepped forth and answered with a binding word:\n"
        "'Where you shall ride, there shall I stand or fall;\n"
        "No shadow takes you while I yet endure.'\n"
        "So were they bound in oath and brotherhood.\n");

    addChapter("The Crossing of the Lonis",
        "The river Lonis ran both deep and cold,\n"
        "A boundary drawn by fear and ancient war.\n"
        "Yet Bregandil did not delay nor doubt,\n"
        "But called his host to make the crossing swift.\n"
        "'What is a river,' thus he spoke aloud,\n"
        "'But water set between the brave and fate?'\n"
        "So spoke Bregandil, and the banners moved.\n"
        "Through current strong and biting winter wind,\n"
        "They passed into the lands of shadowed rule.\n"
        "The people there beheld their coming hosts,\n"
        "And many cast aside their tyrant's yoke.\n"
        "They came in numbers, bearing hope once more,\n"
        "And swore their strength to Bregandil's command.\n"
        "Thus grew his host not only by the sword,\n"
        "But by the will of those who chose him lord.\n");

    addChapter("The Taking of the Cities",
        "Carandur fell and rose again in flame,\n"
        "Dor-Lonis too was wrested from the foe.\n"
        "In every street the clash of iron rang,\n"
        "And none could say which side would claim the day.\n"
        "Then Cuilornir amid the press of war\n"
        "Cried out to those who faltered in their ranks:\n"
        "'Stand firm! For every step we yield in fear\n"
        "Shall cost us twice when next we dare advance!'\n"
        "So spoke Cuilornir, and the line held fast.\n"
        "Then Bregandil, with blade drawn bright in hand,\n"
        "Struck where the enemy was weakest found.\n"
        "'Now forward!' was his cry above the din,\n"
        "'And let this day be written in our names!'\n"
        "So fell the cities, taken back by will.\n");

    addChapter("The Founding of Eledhel",
        "In the year three hundred eleven marked,\n"
        "They came upon a fair and open land.\n"
        "There Bregandil beheld both hill and stream,\n"
        "And spoke as one who sees beyond the hour:\n"
        "'Here shall a city rise against the dark,\n"
        "Not wrought in fear, but founded firm in hope.\n"
        "Let stone be laid where none has dared before,\n"
        "And let this place be named Eledhel hence.'\n"
        "So spoke Bregandil, and the work began.\n"
        "Men labored there with purpose newly found,\n"
        "And walls were raised where once was only field.\n"
        "Cuilornir stood watch as the first guard sworn,\n"
        "And chose the few who would not yield nor break.\n"
        "Thus was the Aegis Guard first brought to form,\n"
        "A shield for all who dwelt within those walls.\n");

    addChapter("The Crowning",
        "When word was sent, Eldarion himself\n"
        "Came eastward to behold what had been made.\n"
        "He saw the walls, the people, and the will,\n"
        "And knew a realm had risen from the strife.\n"
        "Before them all, he took the crafted crown,\n"
        "And placed it on his nephew's steadfast brow.\n"
        "Then spoke the king before the gathered host:\n"
        "'Not mine this realm, nor mine the right to rule,\n"
        "But his who claimed it first by deed and oath.\n"
        "Let all men know this crown is justly won.'\n"
        "So spoke Eldarion, and none gainsaid.\n"
        "Then Bregandil in turn addressed his folk:\n"
        "'This land is yours as much as it is mine;\n"
        "Together shall we guard what we have made.'\n"
        "So was he crowned, first king of Eledhel.\n");

    addChapter("The Oath Fulfilled",
        "Thus was the oath once sworn brought into truth,\n"
        "Beyond the river, in a hostile land.\n"
        "What was but war became a kingdom fair,\n"
        "And what was fear was turned to steadfast hope.\n"
        "Men speak his name where banners yet are raised,\n"
        "And tell of how he did not turn aside.\n"
        "So spoke Bregandil, and so he did.\n"
        "And Cuilornir, who stood beside him still,\n"
        "Is named wherever loyalty is praised.\n"
        "Let those who hear remember what was done:\n"
        "That crowns are not by lineage alone,\n"
        "But forged in trial, and proven under fire.\n"
        "So ends the lay, yet not the tale it tells.\n");
}
