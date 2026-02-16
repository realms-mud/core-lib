//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("physical");
    addHitDictionary(({
        "crush", "squeeze", "constrict", "compress", "coil around" }));

    addSimileDictionary(({
        "tightening around ##TargetPossessive## ##BodyPart##", "with a "
        "bone-crushing force", "squeezing ##TargetPossessive## ##BodyPart## "
        "in a vise-like grip" }));

    addMissMessage("##AttackerName## ##Infinitive::coil## around empty air.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## coils.", "1-150");
}
