inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("neutral");
    addHitDictionary(({
        "strike", "hit", "damage", "thump", "lash" }));

    addSimileDictionary(({
        "with waves of colorless energy", "with a shock of colorless force",
        "soundly", "resoundingly" }));
        
    addMissMessage("##AttackerName## ##Infinitive::get## a not-so-bright "
            "look on ##AttackerPossessive## face.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-50");
}



