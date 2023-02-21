//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("bolt");
    addHitDictionary(({
        "impale", "pierce", "puncture", "skewer", "shoot", "riddle",
        "perforate", "stick", "prick", "hit" }));

    addSimileDictionary(({
        "expertly with a bolt", 
        "with a well-aimed quarrel", 
        "through ##TargetPossessive::Name## ##BodyPart## with a bolt",
        "with a quarrel" }));

    addMissMessage("##AttackerName## ##Infinitive::shoot## a bolt at"
        " nothing whatsoever!");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## from ##AttackerPossessive##"
        " ##AttackerWeapon##.", "1-150");
}
