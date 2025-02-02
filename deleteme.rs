use std::{env, fs, process, thread, time::Duration};
use std::os::windows::process::CommandExt;

fn main() {
    let exe_path = env::current_exe().unwrap();
    let src_path = file!().replace("\\", "/");
    let pdb_path = exe_path.with_extension("pdb");

    if env::args().len() > 1 {
        thread::sleep(Duration::from_millis(500));
        let _ = fs::remove_file(env::args().nth(2).unwrap());
        let _ = fs::remove_file(env::args().nth(3).unwrap());
        let _ = fs::remove_file(env::args().nth(4).unwrap());
        return;
    }

    if cfg!(target_os = "windows") {
        let _ = process::Command::new("cmd")
            .args(["/C", "timeout /t 0.5 & del", exe_path.to_str().unwrap()])
            .creation_flags(0x08000000)
            .spawn();
    } else {
        let _ = process::Command::new("sh")
            .arg("-c")
            .arg(format!("sleep 0.5 && rm -f {}", exe_path.to_string_lossy()))
            .spawn();
    }

    let _ = fs::remove_file(&src_path);
    let _ = fs::remove_file(&pdb_path);
    process::exit(0);
}
