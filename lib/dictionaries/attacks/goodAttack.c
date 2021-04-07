//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("good");
    damagesEthereal();
    addHitDictionary(({
        "smite", "slam", "punish", "flatten", "crush", "hammer", "pound",
        "maul" }));

    addSimileDictionary(({
        "with a pure silvery force", "with a blast of blinding white light",
        "with a shining blade of silver light" }));

    addMissMessage("##AttackerName## ##Infinitive::smile## pleasantly " +
        "at ##TargetName##.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
