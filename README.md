# pipex

#### Build and running the project
```sh
make && ./pipex file1 cmd1 cmd2 file2
```

#### Examples
```sh
$> < file1 cmd1 | cmd2 > file2

$> < in ls -l | wc -l > outfile
$> < in grep a1 | wc -w > outfile


$> ./pipex file1 cmd1 cmd2 file2

$> ./pipex in "ls -l" "wc -l" out
$> ./pipex in "grep a1" "wc -w" out
```

#### Ressources
- [Process control](https://cs61.seas.harvard.edu/site/2021/ProcessControl/)
- [Pipes, forks & dups](https://www.rozmichelle.com/pipes-forks-dups/)
- [Pipe: an inter-process communication method](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
- [Bash pipe tutorial](https://linuxhint.com/bash_pipe_tutorial/)
- [Pipelines (Bash reference manual)](https://www.gnu.org/software/bash/manual/html_node/Pipelines.html)
