//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("physical");
    addHitDictionary(({
        "stomp", "trample", "pummel", "pound", "smack", "assault" }));

    addSimileDictionary(({
        "smashing into ##TargetPossessive## ##BodyPart##", "repeatedly in "
        "the ##BodyPart##" }));

    addMissMessage("##AttackerName## ##Infinitive::rear## up wildly and "
        "##Infinitive::paw## at the air with ##AttackerPossessive## hooves.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## hooves.", "1-150");
}
