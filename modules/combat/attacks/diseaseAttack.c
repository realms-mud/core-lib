//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();
    setDamageType("disease");
    addHitDictionary(({
        "infect", "beplague", "inject", "inflict", "impart", "defile",
        "corrupt", "assail" }));

    addSimileDictionary(({
        "with a horrible disease", "with a horrfying sickness",
        "with a nasty infection", "with a debilitating illness" }));
        
    addMissMessage("##AttackerName## ##Infinitive::sputter## something about"
        " icky germs.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##. Eeew.",
        "1-50");
}



