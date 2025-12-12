//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("steam");
    addHitDictionary(({
        "scald", "blast", "burn", "sear", "spray", "engulf", "blister" }));

    addSimileDictionary(({
        "with a jet of scalding steam", "with a billowing cloud of searing vapor",
        "with a hissing blast of superheated mist", 
        "with a roaring geyser of boiling steam" }));

    addMissMessage("##AttackerName## ##Infinitive::release## a pathetic puff of "
        "lukewarm vapor that dissipates harmlessly.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "default");
    addHitMessage("##AttackerName## ##Infinitive::envelop## ##TargetName## in "
        "a scalding cloud of steam, blistering ##TargetPossessive## ##BodyPart##.",
        "51-150");
}
