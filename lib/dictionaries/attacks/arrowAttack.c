//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("arrow");
    addHitDictionary(({
        "impale", "pierce", "puncture", "skewer", "shoot", "riddle",
        "perforate", "stick", "prick", "hit" }));

    addSimileDictionary(({
        "expertly with an arrow", 
        "with a well-aimed arrow", 
        "through ##TargetPossessive::Name## ##BodyPart## with an arrow",
        "with an arrow" }));

    addMissMessage("##AttackerName## ##Infinitive::shoot## an arrow at"
        " nothing whatsoever!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## from ##AttackerPossessive##"
        " ##AttackerWeapon##.", "1-150");
}
