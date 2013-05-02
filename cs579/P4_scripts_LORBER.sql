/* Terry Lorber <tgl@bu.edu> */
/* CS579 Spring 2013 */
/* Project Part4 */

create table person_del_log (
       ssn        char(9) not null,
       name       varchar(32) not null,
       username   varchar(32) not null,
       deleted_at timestamp not null
);


create function del_person_stamp() returns trigger as $del_person_stamp$
  begin
    insert into person_del_log (ssn, name, username, deleted_at)
    values (OLD.ssn, OLD.name, current_user, now()); 
  end;
$del_person_stamp$ language plpgsql;

create trigger log_person_deletion  after delete on person
  for each row execute procedure del_person_stamp();

   
