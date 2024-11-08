//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("bullet");
    addHitDictionary(({
        "impale", "pierce", "puncture", "skewer", "shoot", "riddle",
        "perforate", "stick", "prick", "hit" }));

    addSimileDictionary(({
        "expertly with a bullet", 
        "with a well-aimed bullet", 
        "through ##TargetPossessive::Name## ##BodyPart## with a bullet",
        "with a bullet" }));

    addMissMessage("##AttackerName## ##Infinitive::shoot## a bullet at"
        " nothing whatsoever!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## from ##AttackerPossessive##"
        " ##AttackerWeapon##.", "1-150");
}
