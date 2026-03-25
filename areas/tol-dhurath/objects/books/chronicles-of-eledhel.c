//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Chronicle of Eledhel");
    set("short", "A book titled 'Chronicle of Eledhel'");
    set("title",
        "The Chronicle of Eledhel: Being an Account of Its Founding "
        "and Early Years");
    set("aliases",
        ({ "chronicle of eledhel", "eledhel chronicle", "book",
           "account of eledhel" }));
    set("long",
        "A carefully kept volume, written in a steady and practiced "
        "hand. Its tone is measured, its judgments deliberate. It "
        "records the founding of Eledhel and the ordering of its "
        "realm in the years following the great wars.");

    addChapter("On the Founding",
        "In the year three hundred eleven, Eledhel was founded,\n"
        "not in peace, but in the aftermath of hard-won war.\n"
        "The land chosen lay east of the Lonis River,\n"
        "a place contested, yet well-suited for defense.\n"
        "Bregandil, nephew to King Eldarion,\n"
        "was first among those who resolved to remain.\n"
        "It is recorded that he chose the site himself,\n"
        "preferring strength of ground over ease of living.\n"
        "Thus the first works were not halls, but walls,\n"
        "and not markets, but storehouses and guard posts.\n"
        "This decision, though severe, proved wise,\n"
        "for the years that followed were not without trial.\n"
        "Many who came after remarked upon this:\n"
        "that Eledhel was from its first a place of purpose,\n"
        "not of luxury nor idle ambition.\n");

    addChapter("On the Crowning of Bregandil",
        "In the year three hundred fourteen, the crown was set.\n"
        "Eldarion himself came east for this purpose,\n"
        "bringing with him both authority and witness.\n"
        "The act was conducted without excess display,\n"
        "and before those whose labor had raised the city.\n"
        "It is said the king spoke plainly at that time:\n"
        "'What is founded by deed shall be ruled by deed.'\n"
        "By this, he affirmed Bregandil's right to govern,\n"
        "not by birth alone, but by proven action.\n"
        "The crown itself was of modest design,\n"
        "lacking the ornament seen in older courts.\n"
        "This too was taken as deliberate,\n"
        "a sign that the new realm valued endurance\n"
        "above display, and substance above form.\n");

    addChapter("On the Aegis Guard",
        "Among the first institutions established\n"
        "was the body later named the Aegis Guard.\n"
        "It was formed under Cuilornir, companion\n"
        "to the king and a man of steady judgment.\n"
        "The purpose of this guard was not ceremony,\n"
        "but the direct defense of crown and city.\n"
        "Selection was made with notable care,\n"
        "favoring discipline over noble birth.\n"
        "Those admitted were bound by strict oath,\n"
        "and held to standards not easily met.\n"
        "In later years, their reputation grew,\n"
        "such that their presence alone deterred unrest.\n"
        "It is no exaggeration to state\n"
        "that their early formation secured the realm\n"
        "against dangers both within and without.\n");

    addChapter("On Settlement and Growth",
        "In the years following the founding,\n"
        "settlement increased at a measured pace.\n"
        "Many came from Ardain and Eneldhor,\n"
        "drawn by promise, but tempered by reality.\n"
        "The land required labor before yield,\n"
        "and hardship was common in early seasons.\n"
        "Yet order was maintained in distribution,\n"
        "and records show careful management of stores.\n"
        "Craftsmen were given defined quarters,\n"
        "and roads were laid with future use in mind.\n"
        "No rapid expansion was permitted\n"
        "where it would weaken the city's defenses.\n"
        "Thus growth, though slower than some desired,\n"
        "proved stable and resistant to disruption.\n");

    addChapter("On Governance",
        "The governance of Eledhel in its early years\n"
        "was marked by clarity and restraint.\n"
        "Bregandil did not rule in isolation,\n"
        "but relied upon a council of proven men.\n"
        "Matters of law were recorded in writing,\n"
        "reducing dispute and preserving precedent.\n"
        "It is noted that judgment was often firm,\n"
        "yet seldom arbitrary or without cause.\n"
        "This consistency strengthened public trust,\n"
        "particularly among those newly settled.\n"
        "Unlike older realms, burdened by custom,\n"
        "Eledhel was able to define its order anew.\n"
        "This advantage was not squandered,\n"
        "but shaped into a durable foundation.\n");

    addChapter("On Relations with the West",
        "Relations with western realms remained strong,\n"
        "particularly with the house of Eldarion.\n"
        "Aid was given when required,\n"
        "though not without expectation of return.\n"
        "Trade routes were established in due course,\n"
        "linking Eledhel to older centers of power.\n"
        "It is recorded that these ties were managed\n"
        "with care, so as not to invite dependence.\n"
        "Eledhel was not conceived as an outpost,\n"
        "but as a realm in its own right.\n"
        "This distinction was maintained in policy,\n"
        "and reinforced in all formal exchanges.\n"
        "Thus alliance did not become subservience,\n"
        "nor cooperation a loss of sovereignty.\n");

    addChapter("Conclusion",
        "From these beginnings, the realm endured.\n"
        "It was neither the largest nor the richest,\n"
        "but it was among the most deliberate.\n"
        "Founded in war, it did not forget war,\n"
        "yet it did not permit war to define it wholly.\n"
        "Those who study its early years\n"
        "often remark upon this balance.\n"
        "Strength was maintained without excess,\n"
        "and growth pursued without haste.\n"
        "Such qualities are not easily achieved,\n"
        "nor often sustained across generations.\n"
        "That Eledhel did so is worthy of record.\n"
        "Let this account stand for those who follow,\n"
        "as both example and measured instruction.\n");
}
