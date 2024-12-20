//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("energy");
    damagesEthereal();
    addHitDictionary(({
        "blast", "beam", "flare", "radiate", "irradiate", "coruscate" }));

    addSimileDictionary(({
        "with a vivid red bolt of energy", "with a searing bolt of energy",
        "with a blinding yellow bolt of energy", "with a scintillating " +
        "blue bolt of energy" }));

    addMissMessage("##AttackerName## ##Infinitive::look## confused as tiny "
        "motes of light encircle ##AttackerPossessive## head.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
