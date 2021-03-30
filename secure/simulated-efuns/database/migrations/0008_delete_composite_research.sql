CREATE PROCEDURE `deleteCompositeResearch` ( p_playername varchar(40), 
    p_name varchar(100), p_constraint varchar(100)
)
BEGIN
    declare compositeId int;

    select compositeResearch.id into compositeId
    from compositeResearch
    inner join players on compositeResearch.playerid = players.id
    where players.name = p_playername and 
          compositeResearch.name = p_name and
          compositeResearch.constraint = p_constraint;

    if compositeId is not null then
        delete from compositeResearchElements 
        where compositeresearchid = compositeId;

        delete from compositeResearch
        where id = compositeId;
    end if;
END;
##
