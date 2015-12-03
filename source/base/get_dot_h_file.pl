#!/usr/bin/perl

# has support for: template, constructor, destructor
my $first=1;
while(<>) {
	if(/^([\w<>]*) ([A-Z_]\w*)::(\w*)\((.*)\)/) 
	{
		print get_start($2) if($first && !($first=0));
		print "\t$1 $3($4);\n";
	} 
	elsif(/^([A-Z_]\w*)::(~)?\1\((.*)\)/) 
	{
		# constructor and destructor
		print get_start($1) if($first && !($first=0));
		print "\t$2$1($3);\n";
	}
}
print "};\n#endif";

sub get_define_guard{
	my $class_name=shift;
	$class_name=~ s/([A-Z])/\_\1/g;
	my $macro=uc $class_name."_H_\n";
	my $guard="#ifndef $macro#define $macro\n";
	return $guard;
}

sub get_class_decl{
	my $class_name=shift;
	my $comment="//include here\n\n"."//description of the class here\n";
	my $stmt=$comment . "class $class_name\n{\npublic:\n";
	return $stmt;
}

sub get_start{
	my $class_name=shift;
	return get_define_guard($class_name) . get_class_decl($class_name);
}
