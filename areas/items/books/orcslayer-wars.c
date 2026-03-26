//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Orcslayer Wars");
    set("short", "A grim chanson of war and ruin");
    set("title", "The Orcslayer Wars: A Song of Iron and Ash");
    set("aliases", ({ "orcslayer wars", "song of iron", "ash song",
        "chanson", "book" }));
    set("long",
        "A weighty codex bound in dark leather, its verses stern "
        "and measured. Here are sung the deeds of kings and captains, "
        "their vows, their defiance, and the ruin they endured.");

    addChapter("Prologue",
        "Hear now, you who gather where the hearth burns low,\n"
        "Of iron days and oaths that were not broken.\n"
        "Not lightly do I speak of what befell,\n"
        "For blood once paid the price of every word.\n"
        "Attend the names, remember what was lost,\n"
        "For silence is the grave of all great deeds.\n"
        "Let no man say: 'This came by fate alone,'\n"
        "For men chose steel, and thereby shaped their doom.\n"
        "So is this song set forth in measured line,\n"
        "Of kings who stood, and those who would not yield.\n"
        "Mark well the tide that rose from shadowed east,\n"
        "And how it broke on will and tempered blade.\n"
        "So begins the war of ash and iron.\n");

    addChapter("The Crowning of Elonoch",
        "In one hundred six was Elonoch crowned king,\n"
        "Lord of Dor-Temnost, stern of eye and will.\n"
        "Before his lords he spoke, and thus declared:\n"
        "'A crown is not a circlet wrought for ease,\n"
        "But iron laid upon a mortal brow.\n"
        "Who bears it must enlarge or else be crushed.'\n"
        "So spoke the king, and many bent the knee.\n"
        "Gildaer fell, Celebgaer followed soon,\n"
        "Their banners lowered to his rising star.\n"
        "Some came by oath, and some through quiet fear,\n"
        "Yet all were bound beneath his growing hand.\n"
        "But even then, beneath that gathering might,\n"
        "There stirred a shadow none had yet beheld.\n");

    addChapter("The Sack of Arnost",
        "In one hundred eight, dread fell upon the land,\n"
        "When Arnost's walls were broken in a night.\n"
        "No horn was heard that brought relief or aid,\n"
        "Only the cry of death in every street.\n"
        "Two hundred thousand souls and forty more\n"
        "Were cast to ruin by the orcish hand.\n"
        "A captain cried before the final breach:\n"
        "'Stand fast! Let none say Arnost died in fear!'\n"
        "Yet iron failed, and numbers overwhelmed.\n"
        "Their heads were sent upon the Hillgarath,\n"
        "A silent fleet that bore a message grim.\n"
        "Then rose the lords in wrath and bitter oath:\n"
        "'By ash and blood, this shall be answered well!'\n"
        "So was the Orcslayer War begun.\n");

    addChapter("Siege and Ash",
        "In one hundred nine, the siege of Mirost came,\n"
        "Encircled fast by fires on every hill.\n"
        "Dhuras Keep was taken, stone to dust,\n"
        "Its defenders slain where once they held the gate.\n"
        "A lone survivor carved upon the wall:\n"
        "'We fell, yet we shall rise more strong than this.'\n"
        "Hillgarath sent its riders forth in haste,\n"
        "To Eneldhor with words that burned like flame.\n"
        "Serach answered, swift to muster arms,\n"
        "And Arendor prepared again for war.\n"
        "Then spoke a captain to his weary men:\n"
        "'Better to die with blade in hand and oath,\n"
        "Than live to see our halls in ashes laid.'\n"
        "So held they fast beneath the gathering dark.\n");

    addChapter("The Coming of Eldarion",
        "In one hundred eleven rode two into war:\n"
        "Eldarion, son of Arendor the wise,\n"
        "And Elthoron of Halbaladh's proud line.\n"
        "Before the host, Eldarion raised his voice:\n"
        "'Men of the West, I come not here for name,\n"
        "Nor glory sung in halls when I am dust.\n"
        "I come that none shall say we did not stand\n"
        "When darkness rose to swallow all we knew.'\n"
        "Then Elthoron beside him made his boast:\n"
        "'Where he shall stand, there shall I stand as well;\n"
        "No blade shall reach him while I yet draw breath.'\n"
        "So were they bound in word as well as deed,\n"
        "And hope was kindled in the watching host.\n");

    addChapter("The Fall of Utumnadh",
        "In one hundred twelve they marched on Utumnadh,\n"
        "A fortress black, long rooted in the night.\n"
        "Before the walls, Eldarion gave command:\n"
        "'Break now this gate, and let no shadow stand!\n"
        "For every stone that falls redeems the slain\n"
        "Whose blood yet cries from Arnost's silent streets.'\n"
        "The battle raged, the walls were torn away,\n"
        "And fire consumed the darkened halls within.\n"
        "Elthoron cried amid the final breach:\n"
        "'See now! The night itself is driven back!'\n"
        "So fell the stronghold, broken into ash,\n"
        "And all who saw it knew the tide had turned.\n"
        "Then Eldarion returned unto his home,\n"
        "His oath fulfilled, yet war not ended still.\n");

    addChapter("The Expanding War",
        "Yet war does not end where one victory lies.\n"
        "In one hundred fourteen, Elonoch declared\n"
        "His will upon the realm of Kharand's kings.\n"
        "Before his court, he spoke in iron tones:\n"
        "'What we have taken, we shall not release.\n"
        "What stands apart shall soon be brought to heel.'\n"
        "So Uladar fell beneath his gathering might,\n"
        "And Agrendin was taken soon thereafter.\n"
        "Kharand itself bowed low before his hand.\n"
        "Yet some there were who whispered in the dark:\n"
        "'A realm that grows by war must feed on war.'\n"
        "Still Elonoch pressed on and would not yield,\n"
        "And thus the flames spread wider through the land.\n");

    addChapter("Epilogue",
        "So have you heard the first of many blows,\n"
        "That shaped the long and bitter years to come.\n"
        "Remember well the vows that here were sworn,\n"
        "And how they bound the living to the dead.\n"
        "For every boast must one day meet its test,\n"
        "And every oath be answered, well or ill.\n"
        "If wisdom lives in tales of former days,\n"
        "Then let this stand as warning carved in ash.\n"
        "Guard well your gates, and trust not fragile peace,\n"
        "For shadow waits where watchfulness grows dim.\n"
        "So ends this song, yet not the war it tells.\n");
}
