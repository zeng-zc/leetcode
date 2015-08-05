perl -ne '@arr=split; foreach $wd (@arr){$res{$wd}++}; END{foreach (sort
{($res{$b} <=> $res{$a}) || ($a <=> $b)} keys %res) {print "$_ $res{$_}\n";}}'
