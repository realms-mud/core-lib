//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Dissenting Account of the Eastern Wars");
    set("short", "A book about Eledhel's rise");
    set("title", "Concerning "
        "Bregandil and the Seizure of the East");
    set("aliases",
        ({ "dissenting account", "eastern wars critique",
           "bregandil critique", "book" }));
    set("long",
        "A severe and deliberate work, written in a restrained hand. "
        "Its author questions the commonly accepted account of the "
        "eastern campaigns and the founding of Eledhel.");

    addChapter("On the So-Called Founding",
        "It is often written that Eledhel was founded in hope,\n"
        "yet this deserves closer examination.\n"
        "The lands east of the Lonis were not empty,\n"
        "nor without long-standing claims and histories.\n"
        "That they were weakened by war is certain,\n"
        "but weakness does not void possession.\n"
        "Bregandil is said to have chosen the site,\n"
        "yet no record shows consent of those displaced.\n"
        "Thus what is named founding may also be called taking.\n"
        "That it was done with skill is not disputed.\n"
        "Whether it was done with right remains unclear.\n");

    addChapter("On Bregandil's Claim",
        "Much is made of Bregandil's merit in war,\n"
        "and indeed he showed both courage and resolve.\n"
        "Yet merit in battle does not alone confer rule.\n"
        "It is said he claimed no crown by birth,\n"
        "yet he did not refuse it when offered.\n"
        "The presence of Eldarion at the crowning\n"
        "is taken as proof of legitimacy.\n"
        "It may also be taken as influence.\n"
        "For what is granted by a greater king\n"
        "is seldom free of expectation.\n"
        "Thus the independence of Eledhel,\n"
        "so often praised, may not be complete.\n");

    addChapter("On the Fall of Dor-Temnost",
        "Dor-Temnost is remembered chiefly for cruelty,\n"
        "and not without cause in certain reigns.\n"
        "Yet it must be noted that it held order\n"
        "across lands long divided and prone to war.\n"
        "Its fall did not bring immediate peace,\n"
        "but rather a scattering of smaller conflicts.\n"
        "Where once there was one power, there were many.\n"
        "Some welcomed this, others did not.\n"
        "It is the habit of victors to condemn\n"
        "what they have replaced.\n"
        "Whether all such condemnation is just\n"
        "should be considered with care.\n");

    addChapter("On the Aegis Guard",
        "The Aegis Guard is praised as incorruptible,\n"
        "and perhaps it was so in its earliest years.\n"
        "Yet any body granted such authority\n"
        "must be regarded with measured caution.\n"
        "They answer first to the crown,\n"
        "and only thereafter to law.\n"
        "This order is seldom reversed in time.\n"
        "That they preserved stability is clear.\n"
        "Whether they constrained dissent\n"
        "is less frequently recorded.\n");

    addChapter("On Settlement",
        "Those who came east are said to have sought hope,\n"
        "yet many came from necessity rather than choice.\n"
        "War and scarcity drove them from their homes.\n"
        "Eledhel offered structure where little remained.\n"
        "This does not diminish its achievement,\n"
        "but it alters the nature of its appeal.\n"
        "A realm built by the displaced\n"
        "is not the same as one freely chosen.\n"
        "Its strength may be great,\n"
        "but its origins are not without hardship.\n");

    addChapter("On Memory and Record",
        "It is the tendency of later years\n"
        "to arrange events into pleasing order.\n"
        "Heroes are clarified, and doubts reduced.\n"
        "Yet those who lived through such times\n"
        "rarely spoke with such certainty.\n"
        "Accounts differ, and not without reason.\n"
        "This work does not seek to overturn,\n"
        "but to complicate what is too simple.\n"
        "For in complexity there is often truth.\n"
        "And in truth, a clearer understanding.\n");
}
